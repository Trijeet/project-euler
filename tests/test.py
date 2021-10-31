import os
import sys
import json
from colorama import Fore, Back, Style

with open('solutions.json') as solutions:
    data = json.load(solutions)
    total_tests = len(data)
    correct_tests = 0
    failed_tests = 0
    for filename, answer in data.items():
        #Execute file and get answer
        exec_file = filename + ".exe"
        cmd = "g++ -w ../solutions/" + filename + " -o " + exec_file
        if os.system(cmd) != "":
            cmd = "./" + exec_file
            os_file = os.popen(cmd)
            result = os_file.read()
            os_file.close()

        #Compare solutions
        if answer.strip() == result.strip():
            correct_tests += 1
            print(Fore.BLACK + Back.GREEN + "Test case passed for " + filename + Style.RESET_ALL)
        else:
            failed_tests += 1
            print(Back.RED + "Test case failed for " + filename + Style.RESET_ALL)

    print("Stats:\n" + str(correct_tests) + " passed out of " + str(total_tests))

    #Removing all exec files
    cmd = "rm -rf *.exe"
    result = os.system(cmd)
    if result:
        print("Error in deleting files " + result)

    sys.exit(failed_tests)
