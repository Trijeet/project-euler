import os
import sys
import json
from colorama import Fore, Back, Style

failed_tests = -1
with open('solutions.json') as solutions:
    data = json.load(solutions)
    total_tests = len(data)
    correct_tests = 0
    failed_tests = 0
    for key in data:
        filename = key
        answer = data[key]

        #Execute file and get answer
        exec_file = filename + ".exe"
        cmd = "g++ ../solutions/" + filename + " -o " + exec_file
        result = os.system(cmd)
        if (result):
            print("Error caught at running file " + filename)
            print(result)
            result = "NaN"
        else:
            cmd = "./" + exec_file
            os_file = os.popen(cmd)
            result = os_file.read()
            os_file.close()
        #Compare solutions
        if (answer.strip() == result.strip()):
            correct_tests += 1
            print(Fore.BLACK + Back.GREEN + "Test case passed for " + filename, end = "")
            print(Style.RESET_ALL)
        else:
            failed_tests += 1
            print(Back.RED + "Test case failed for " + filename, end = "")
            print(Style.RESET_ALL)
    print("Stats:")
    print(str(correct_tests) + " passed out of " + str(total_tests))
    #Removing all exec files
    cmd = "rm -rf *.exe"
    result = os.system(cmd)
    if (result):
        print("Error in deleting files")
        print(result)
if failed_tests != 0:
    sys.exit(1)
else:
    sys.exit(0)
