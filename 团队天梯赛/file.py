import os
# 修正文件名
for file in os.listdir():
	if '-0' not in file:
		os.rename(file, file.replace('-', '-0'))
# 添加赛题信息
# d = {'L1': 48,
# 	 'L2': 24,
# 	 'L3': 18,
# }
# list_dir = os.listdir()
# for each in d:
# 	for n in range(1, d[each]+1):
# 		file = str.format("%s-%03d.c" % (each, n))
# 		with open(file, 'r+') as f:
# 			lines = f.readlines()
# 			if not f.readlines[0].startswith("http://"):
# 				f.write("https://www.patest.cn/contests/gplt/%s\n" % file[:-2])
# 				f.writelines(lines)



