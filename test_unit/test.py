import random
import n2w

# print(' '.join(str(e) for e in random.sample(range(10), 10)))
lst = random.sample(range(1000), 1000);

for i in lst:
	# print(n2w.convert(i).replace(" ", "") + " " + str(i),end=" ");
	print("test_insert.insert(lib_used::make_pair(std::string(\"" +n2w.convert(i).replace(" ", "") + "\")," + str(i) + "));");