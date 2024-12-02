#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QRegularExpression>

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Helper function to convert QString to lowercase
QString MainWindow::toLowerCase(const QString &str) {
    return str.toLower();
}

// Helper function to remove punctuation, keeping internal hyphens
QString MainWindow::removePunctuation(const QString &word) {
    QString result;
    for (int i = 0; i < word.length(); ++i) {
        QChar c = word[i];
        if (c.isLetterOrNumber() || (c == '-' && i > 0 && i < word.length() - 1)) {
            result += c;
        }
    }
    return result;
}

// Helper function to check if the word contains the search word
bool MainWindow::containsWord(const QString &word, const QString &searchWord) {
    if (word == searchWord) {
        return true;
    }

    QStringList parts = word.split('-', Qt::SkipEmptyParts);
    for (const QString &part : parts) {
        if (part == searchWord) {
            return true;
        }
    }
    return false;
}

// Function to count word frequency
void MainWindow::countWordFrequency(const QString &searchWord, int &total_words, int &word_count) {
    total_words = 0;
    word_count = 0;

    QString loweredSearchWord = toLowerCase(searchWord);

    // Use regex to split text into words
    QRegularExpression wordRegex("\\b\\w+\\b");
    QRegularExpressionMatchIterator it = wordRegex.globalMatch(fileContent);

    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        QString currentWord = match.captured(0);
        QString cleanedWord = removePunctuation(toLowerCase(currentWord));
        if (cleanedWord.isEmpty()) {
            continue;
        }
        total_words++;

        if (containsWord(cleanedWord, loweredSearchWord)) {
            word_count++;
        }
    }
}

// Load File Button
void MainWindow::on_loadFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) {
        return; // Cancelled
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file: %1").arg(fileName));
        return;
    }

    QTextStream in(&file);
    fileContent = in.readAll();
    file.close();

    // Display the file content in the text display area
    ui->textEdit->setPlainText(fileContent);
}

// Find Button
void MainWindow::on_findButton_clicked()
{
    QString keyword = ui->lineEdit->text().trimmed();
    if (keyword.isEmpty()) {
        QMessageBox::information(this, tr("Input Required"), tr("Please enter a keyword to search for."));
        return;
    }

    if (fileContent.isEmpty()) {
        QMessageBox::information(this, tr("No File Loaded"), tr("Please load a text file first."));
        return;
    }

    int total_words = 0;
    int word_count = 0;

    countWordFrequency(keyword, total_words, word_count);

    // Update the label with the results
    QString result = QString("Total Words Searched: %1\nInstances of '%2': %3").arg(total_words).arg(keyword).arg(word_count);
    ui->label_2->setText(result);
}

// Save File Button
void MainWindow::on_saveFileButton_clicked()
{
    QString resultText = ui->label_2->text();
    if (resultText.isEmpty()) {
        QMessageBox::information(this, tr("No Results"), tr("There are no results to save."));
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Results"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty()) {
        return; // Cancelled
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot save file: %1").arg(fileName));
        return;
    }

    QTextStream out(&file);
    out << resultText;
    file.close();

    QMessageBox::information(this, tr("Success"), tr("Results saved successfully."));
}
