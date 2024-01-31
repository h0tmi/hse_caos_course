import os
import random

for i in range(10):

    # Number of random values to generate
    # n = random.randint(0, 228)
    n = 0


    # Generate n random float values in the range [0.0, 1.0)
    # random_values = [random.randint(0, 199) for _ in range(n)]

    # Write generated numbers to a file
    input_filename = f"input/input{i}.txt"

    with open(input_filename, 'r') as inp:
        n = inp.read();
    # with open(input_filename, 'w') as input_file:
    #     for value in random_values:
    #         print(value, end=", ", sep=", ")
    #         input_file.write(f"{value}\n")
    #
    # print("END OF ITERATION\n")

    # Execute ./main with the generated input file
    output_filename = f"output2/output{i}.txt"
    command = f"./main < {input_filename} > {output_filename}"
    os.system(command)

    print(f"Output written to {output_filename}")
