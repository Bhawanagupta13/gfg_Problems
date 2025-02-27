import os
import subprocess
from datetime import datetime

# Load GitHub token from environment variable
GITHUB_TOKEN = os.getenv("GITHUB_TOKEN")

if not GITHUB_TOKEN:
    print("Error: GitHub token not found! Set it in environment variables.")
    exit(1)

# Function to save solution
def save_gfg_solution(filename, code):
    with open(filename, "w", encoding="utf-8") as f:
        f.write(code)
    print(f"✅ {filename} saved!")

# Function to push changes to GitHub
def push_to_github(filename):
    try:
        subprocess.run(["git", "add","."], check=True)
        commit_message = f"GFG Solution - {filename}"
        subprocess.run(["git", "commit", "-m", commit_message], check=True)
        subprocess.run(["git", "push", "origin"], check=True)
        print("✅ Code pushed to GitHub successfully!")
    except subprocess.CalledProcessError as e:
        print(f"❌ Error: {e}")

# Main execution
if __name__ == "__main__":
    problem_name = input("Enter problem name (without spaces): ").strip()
    filename = f"{problem_name}.cpp"  # Change extension based on language
    print("Paste your GFG solution code below (Ctrl+V):\n")
    solution_code = "\n".join(iter(input, ""))  # Take multi-line input

    save_gfg_solution(filename, solution_code)
    push_to_github(filename)
