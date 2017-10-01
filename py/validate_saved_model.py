file ="../dataTest/cpp_model.bin"
import struct
with open(file, "rb") as f:
	for i in range(7):
		print(struct.unpack('i', f.read(4))[0])

	print(struct.unpack('f', f.read(4))[0])