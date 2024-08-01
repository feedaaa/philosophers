import os

def concatenate_code_files(directory_path, output_file):
    # Open the output file in write mode
    with open(output_file, 'w') as outfile:
        # Walk through the directory
        for root, dirs, files in os.walk(directory_path):
            for file in files:
                # Check if the file is a code file (e.g., .py for Python)
                if file.endswith('.py'):
                    file_path = os.path.join(root, file)
                    with open(file_path, 'r') as infile:
                        # Write the file name as a comment
                        outfile.write(f"# File: {file}\n")
                        # Write the content of the file
                        outfile.write(infile.read())
                        # Write a newline to separate files
                        outfile.write("\n\n")

# Example usage
directory_path = '/Users/fee/Desktop/misc/philo'
output_file = '/Users/fee/Desktop/misc/philo/all_files'

concatenate_code_files(directory_path, output_file)
