import struct

import numpy as np

LAYER_DENSE = 1
LAYER_CONVOLUTION2D = 2
LAYER_FLATTEN = 3
LAYER_ACTIVATION = 4
LAYER_MAXPOOLING2D = 5

ACTIVATION_LINEAR = 1
ACTIVATION_RELU = 2
ACTIVATION_SOFTMAX = 3


def write_floats(file, floats):
	"""
	Writes floats to file in 1024 chunks.. prevents memory explosion
	writing very large arrays to disk when calling struct.pack().

	step = 1024
	written = 0

	for i in np.arange(0, len(floats), step):
		remaining = min(len(floats) - i, step)
		written += remaining
		file.write(struct.pack('=%sf' % remaining, *floats[i:i + remaining]))

	assert written == len(floats)"""
	floats.tofile(file)
	"""for fl in floats:
		print(fl)
		file.write(struct.pack('f', fl))
		assert False"""


def export_model(model, filename):
	with open(filename, 'wb') as f:

		def write_activation(activation):
			if activation == 'linear':
				f.write(struct.pack('I', ACTIVATION_LINEAR))
			elif activation == 'relu':
				f.write(struct.pack('I', ACTIVATION_RELU))
			elif activation == 'softmax':
				f.write(struct.pack('I', ACTIVATION_SOFTMAX))
			else:
				assert False, "Unsupported activation type: %s" % activation

		model_layers = [l for l in model.layers if type(l).__name__ not in ['Dropout']]
		num_layers = len(model_layers)
		f.write(struct.pack('I', num_layers))

		for layer in model_layers:
			layer_type = type(layer).__name__

			if layer_type == 'Dense':
				weights = layer.get_weights()[0]
				biases = layer.get_weights()[1]
				activation = layer.get_config()['activation']

				f.write(struct.pack('I', LAYER_DENSE))
				f.write(struct.pack('I', weights.shape[0]))
				f.write(struct.pack('I', weights.shape[1]))
				f.write(struct.pack('I', biases.shape[0]))

				weights = weights.flatten()
				biases = biases.flatten()

				write_floats(f, weights)
				write_floats(f, biases)

				write_activation(activation)

			elif layer_type == 'Conv2D':
				assert layer.padding == 'valid', "Only border_mode=valid is implemented"

				weights = layer.get_weights()[0]
				biases = layer.get_weights()[1]
				activation = layer.get_config()['activation']

				f.write(struct.pack('I', LAYER_CONVOLUTION2D))
				f.write(struct.pack('I', weights.shape[0]))
				f.write(struct.pack('I', weights.shape[1]))
				f.write(struct.pack('I', weights.shape[2]))
				f.write(struct.pack('I', weights.shape[3]))
				f.write(struct.pack('I', biases.shape[0]))

				weights = weights.flatten()
				biases = biases.flatten()

				write_floats(f, weights)
				write_floats(f, biases)

				write_activation(activation)

			elif layer_type == 'Flatten':
				f.write(struct.pack('I', LAYER_FLATTEN))

			elif layer_type == 'Activation':
				activation = layer.get_config()['activation']

				f.write(struct.pack('I', LAYER_ACTIVATION))
				write_activation(activation)

			elif layer_type == 'MaxPooling2D':
				assert layer.padding == 'valid', "Only border_mode=valid is implemented"

				pool_size = layer.get_config()['pool_size']

				f.write(struct.pack('I', LAYER_MAXPOOLING2D))
				f.write(struct.pack('I', pool_size[0]))
				f.write(struct.pack('I', pool_size[1]))

			else:
				assert False, "Unsupported layer type: %s" % layer_type


if __name__ == "__main__":
	from keras.models import load_model

	model = load_model("../dataTest/keras_model.h5")
	export_model(model, "../dataTest/cpp_model.bin")
