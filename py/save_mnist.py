""" This file is to save some mnist images in binay
so that they're available for the c++ program."""

from keras.datasets import mnist
import matplotlib.pyplot as plt

(x_train, y_train), (x_test, y_test) = mnist.load_data()

idx = 0
plt.imshow(x_test[idx])
plt.show()
x_test[idx].tofile("../dataTest/unknown_number.bin")
print(x_test.dtype)
