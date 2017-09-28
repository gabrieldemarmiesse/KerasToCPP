""" This file is to save some mnist images in binay
so that they're available for the c++ program."""

from keras.datasets import mnist
import matplotlib.pyplot as plt

(x_train, y_train), (x_test, y_test) = mnist.load_data()

plt.imshow(x_test[0])
plt.show()
x_test[0].tofile("../dataTest/seven.bin")
print(x_test.dtype)
