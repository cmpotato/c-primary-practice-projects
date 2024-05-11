import os
import glob

def count_lines_of_code(directory, extensions):
    total_lines = 0
    for ext in extensions:
        # 使用glob模块递归查找所有指定扩展名的文件
        files = glob.glob(f"{directory}/**/*{ext}", recursive=True)
        for file in files:
            with open(file, 'r', encoding='utf-8', errors='ignore') as f:
                total_lines += len(f.readlines())
    return total_lines

# 指定要搜索的目录
directory_path = "D:\\code\\student-manage-system"  # 修改为你的目录路径
# 指定要统计的文件扩展名
extensions = ['.cpp', '.h']

# 调用函数并打印结果
lines_count = count_lines_of_code(directory_path, extensions)
print(f"Total number of lines in .cpp and .h files: {lines_count}")

# 等待用户按任意键退出
input("Press any key to exit...")