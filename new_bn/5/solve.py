import os
import random

for i in range(5, 10):

    # Number of random values to generate
    n = random.randint(0, 100)

    # Generate n random float values in the range [0.0, 1.0)
    # random_values = [random.randint(0, 199) for _ in range(n)]

    # Write generated numbers to a file
    input_filename = f"input{i}.txt"
    with open(input_filename, 'w') as input_file:
        # for value in random_values:
        print(n, end=", ", sep=", ")
        input_file.write(f"{n}\n")

    # Execute ./main with the generated input file
    output_filename = f"output{i}.txt"
    command = f"./main < {input_filename} > {output_filename}"
    os.system(command)

    with open(output_filename, 'r') as out:
        print(out.read())

    print("Actual:", n // 3)
    print(f"Output written to {output_filename}")
