# import sys
# from PyQt5.QtWidgets import QWidget, QApplication
#
# app = QApplication(sys.argv)
# widget = QWidget()
# widget.resize(800, 600)
# widget.setWindowTitle("Hello, PyQt5!")
# widget.setWindowTitle("你好世界 PyQt5！")
# widget.show()
# sys.exit(app.exec())

import sys
import Main_1   # 导入文件
from PyQt5.QtWidgets import QApplication, QWidget,QMainWindow
if __name__ == '__main__':
    app = QApplication(sys.argv)
    MainWindow = QWidget()
    ui = Main_1.Ui_Frame()  # ui = 文件名
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
