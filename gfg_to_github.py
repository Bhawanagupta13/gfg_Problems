import os
import sys
import subprocess
from datetime import datetime

# Load GitHub token from environment variable
GITHUB_TOKEN = os.getenv("GITHUB_TOKEN")

if not GITHUB_TOKEN:
    print("❌ Error: GitHub token not found! Set it in environment variables.")
    exit(1)

# Function to save solution
def save_gfg_solution(filename, code):
    with open(filename, "w", encoding="utf-8") as f:
        f.write(code)
    print(f"✅ {filename} saved successfully!")

# Function to push changes to GitHub
def push_to_github(filename):
    try:
<<<<<<< HEAD
        subprocess.run(["git", "pull", "--rebase", "origin", "main"], check=True)  # Fetch latest changes
        subprocess.run(["git", "add", "."], check=True)
        commit_message = f"GFG Solution - {filename}"
=======
        subprocess.run(["git", "add", filename], check=True)
        commit_message = f"GFG Solution - {filename} - {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}"
>>>>>>> fefa85b (Fix: Updated script)
        subprocess.run(["git", "commit", "-m", commit_message], check=True)
        subprocess.run(["git", "pull", "--rebase", "origin", "main"], check=True)  # Fetch latest changes
        subprocess.run(["git", "push", "origin", "main"], check=True)
        print("✅ Code pushed to GitHub successfully!")
    except subprocess.CalledProcessError as e:
        print(f"❌ Error: {e}")
# Main execution
if __name__ == "__main__":
    problem_name = input("Enter problem name (without spaces): ").strip()
    filename = f"{problem_name}.cpp"  # Change extension if needed

    print("Paste your GFG solution code below (Press Ctrl+D to finish on Linux/Mac, Ctrl+Z on Windows):\n")
    solution_code = sys.stdin.read().strip()  # Read full input properly

    if not solution_code:
        print("❌ Error: No code provided. Exiting.")
        exit(1)

    save_gfg_solution(filename, solution_code)
    push_to_github(filename)
