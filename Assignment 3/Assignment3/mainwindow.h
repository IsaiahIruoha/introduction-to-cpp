#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadFileButton_clicked();
    void on_findButton_clicked();
    void on_saveFileButton_clicked();

private:
    Ui::MainWindow *ui;
    QString currentFilePath;
    QString fileContent;

    // Helper functions
    QString toLowerCase(const QString &str);
    QString removePunctuation(const QString &word);
    bool containsWord(const QString &word, const QString &searchWord);
    void countWordFrequency(const QString &word, int &total_words, int &word_count);
};

#endif
