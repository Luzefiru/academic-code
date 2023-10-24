import re
import requests

# URLs for the input files
input_urls = [
    "https://raw.githubusercontent.com/danielmiessler/SecLists/master/Passwords/Cracked-Hashes/milw0rm-dictionary.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/master/Passwords/Common-Credentials/10-million-password-list-top-1000000.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/master/Miscellaneous/lang-english.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-75.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-30.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-35.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-40.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-45.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-50.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-55.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-60.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-65.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-70.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/phpbb-cleaned-up.txt",
    "https://raw.githubusercontent.com/danielmiessler/SecLists/395c945627196b6172e6e83a014c964f805e8d48/Passwords/Leaked-Databases/rockyou-25.txt"
]

# Regular expression pattern for lowercase alpha characters (1-8 characters)
pattern = r"^[a-z]{1,8}$"

filtered_lines = []

# Process each input URL
for input_url in input_urls:
    # Download the input file from the URL
    response = requests.get(input_url)

    if response.status_code == 200:
        lines = response.text.splitlines()
        for line in lines:
            line = line.strip()
            if re.match(pattern, line):
                filtered_lines.append(line)
    else:
        print(f"Failed to download the input file from {input_url}.")

# Write the filtered lines to an output file
output_file = "filtered_output.txt"
with open(output_file, "w") as output_file:
    for line in filtered_lines:
        output_file.write(line + "\n")

print(f"Filtered lines saved to {output_file}.")