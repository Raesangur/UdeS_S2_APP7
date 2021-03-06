#include <QGroupBox>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QTextEdit>


class MainWindow : public QMainWindow
{
public:
    MainWindow() = delete;
    MainWindow(QWidget* parent)
    : m_parent{parent ? parent : this},
      m_groupBox{m_parent},
      m_menuBar{m_parent},
      m_file{&m_menuBar},
      m_edit{&m_menuBar},
      m_labelTextBox{&m_groupBox},
      m_textBox{&m_groupBox},
      m_button{m_parent}
    {
        setGeometry(250, 250, 500, 550);
        m_groupBox.setGeometry(5, 25, 490, 490 - 25);

        m_file.setTitle("Fichier");
        m_edit.setTitle(QString::fromStdWString(L"Édition"));

        m_file.addAction("Ouvrir", this, &MainWindow::Open);
        m_file.addAction("Fermer", this, &MainWindow::Close);
        m_file.addAction("Trouver", this, &MainWindow::Find);
        QWidget::connect(&m_button, &QPushButton::clicked, this, &MainWindow::Click);

        m_menuBar.setGeometry(0, 0, 200, 25);
        m_menuBar.addMenu(&m_file);
        m_menuBar.addMenu(&m_edit);

        m_labelTextBox.setText("Texte associé aux actions");
        m_labelTextBox.setGeometry(5, 0, 200, 20);
        m_textBox.setGeometry(5, 25, m_groupBox.width() - 10, m_groupBox.height() - 35);

        m_button.setText("Cliquez ici!");
        m_button.setGeometry(395, 515, 100, 30);
    }

public slots:
    void Open()
    {
        m_textBox.setText(m_textBox.toPlainText() + "Action: Fichier/Ouvrir\n");
    }
    void Close()
    {
        m_textBox.setText(m_textBox.toPlainText() + "Action: Fichier/Fermer\n");
    }
    void Find()
    {
        m_textBox.setText(m_textBox.toPlainText() + "Action: Fichier/Trouver\n");
    }
    void Click()
    {
        m_textBox.setText(m_textBox.toPlainText() + "Action: Bouton\n");
    }

private:
    QWidget*    m_parent;
    QGroupBox   m_groupBox;
    QMenuBar    m_menuBar;
    QMenu       m_file;
    QMenu       m_edit;
    QLabel      m_labelTextBox;
    QTextEdit   m_textBox;
    QPushButton m_button;
};
