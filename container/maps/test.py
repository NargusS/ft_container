import random
import n2w

# print(' '.join(str(e) for e in random.sample(range(10), 10)))

for i in range(100):
	print(n2w.convert(i).replace(" ", "") + " " + str(i),end=" ");