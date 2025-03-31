from PyQt6.QtWidgets import QMainWindow
from PyQt6 import uic
from model import make_uniq, calc_fibs

class MainWindow(QMainWindow):

    def __init__(self):
        super(MainWindow, self).__init__()
        uic.loadUi("./app/view.ui", self)
        self.n = 0
        self.array = []
        self.bindings()

    def bindings(self):
        self.fib_btn.clicked.connect(self.fib_btn_handler)
        self.array_btn.clicked.connect(self.array_btn_hadler)

    def fib_btn_handler(self):
        try:
            self.n = 0
            self.n = int(self.fib_size_lineEdit.text())
            if self.n <= 0:
                raise ValueError
            self.fib_size_lineEdit.setStyleSheet("color:white")
            fibs = calc_fibs(self.n)
            self.fib_lineEdit.setText(' '.join(list(map(str, fibs))))
        except ValueError:
            self.fib_size_lineEdit.setStyleSheet("color:red")
        except Exception:
            self.fib_size_lineEdit.setText("")
        

    def array_btn_hadler(self):
        try:
            self.array.clear()
            self.array = list(map(int, str(self.array_lineEdit.text()).split()))
            if not len(self.array):
                raise ValueError
            self.array_lineEdit.setStyleSheet("color:white")
            rc, uniq = make_uniq(self.array)
            self.set_lineEdit.setText(' '.join(list(map(str, uniq))))
            if rc:
                raise Exception
        except ValueError:
            self.array_lineEdit.setStyleSheet("color:red")
        except Exception:
            self.array_lineEdit.setText("")