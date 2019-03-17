#!/usr/bin/env python3
#sidelength = int(input("Enter side length: "))
sidelength = 4
locations = []

locations = [sidelength]
print(sidelength * "." + '*')
locations = [locations[0] - 1, locations[0] + 1]
while locations[0] != 1:
	print((locations[0]) * "." + '*', end='')
	print(((locations[1] - locations[0])) * "." + "*")
	locations = [locations[0] - 1, locations[1] + 1]
locations = [locations[0] - 1, locations[1] + 1]
while (locations[1] != locations[0]):
	if locations[0] + 1 != locations[1]:
		locations = [locations[0] + 1, locations[1] - 1]
		print(locations[0] * "." + '*', end='')
		print((locations[1] - locations[0]) * "." + "*")
	else:
		print("*")
