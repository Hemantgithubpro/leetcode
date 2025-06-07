import requests
import json
import time
import re

def search_codeforces_problems():
    # List of problem names from the markdown file
    problems = [
        "Three Activities",
        "Make Almost Equal With Mod", 
        "Plus Minus Permutation",
        "Assembly via Minimums",
        "Vika and the Bridge",
        "Contrast Value",
        "Playing in a Casino",
        "Dora and Search",
        "Matryoshkas",
        "Scuza",
        "Removing Smallest Multiples",
        "Friends and the Restaurant",
        "Virus",
        "Mirror Grid",
        "Binary Deque",
        "Stone Age Problem",
        "Dolce Vita",
        "Differential Sorting",
        "Make Them Equal",
        "Grandma Capa Knits a Scarf",
        "Pleasant Pairs",
        "Stable Groups",
        "Prinzessin der Verurteilung",
        "Palindrome Game (easy version)",
        "Same Differences",
        "AND 0 Sum Big",
        "Flip the Bits",
        "M-Arrays",
        "Cat cycle",
        "Districts Connection",
        "Rock and Lever"
    ]
    
    # Get all problems from Codeforces API
    print("Fetching problems from Codeforces API...")
    try:
        response = requests.get("https://codeforces.com/api/problemset.problems")
        data = response.json()
        
        if data['status'] != 'OK':
            print(f"API Error: {data}")
            return
            
        all_problems = data['result']['problems']
        print(f"Found {len(all_problems)} total problems")
        
        # Create a mapping of problem names to their details
        problem_map = {}
        for problem in all_problems:
            name = problem.get('name', '').strip()
            if name:
                problem_map[name.lower()] = problem
        
        # Search for each problem
        results = []
        for i, problem_name in enumerate(problems, 1):
            print(f"Searching for: {problem_name}")
            
            # Try exact match first
            found = False
            for api_name, problem_data in problem_map.items():
                if problem_name.lower() == api_name:
                    contest_id = problem_data['contestId']
                    index = problem_data['index']
                    link = f"https://codeforces.com/problem/{contest_id}/{index}"
                    results.append(f"{i}. [{problem_name}]({link})")
                    print(f"   Found: {link}")
                    found = True
                    break
            
            if not found:
                # Try partial match
                for api_name, problem_data in problem_map.items():
                    if problem_name.lower() in api_name or api_name in problem_name.lower():
                        contest_id = problem_data['contestId']
                        index = problem_data['index']
                        link = f"https://codeforces.com/problem/{contest_id}/{index}"
                        results.append(f"{i}. [{problem_name}]({link})")
                        print(f"   Found (partial): {link}")
                        found = True
                        break
            
            if not found:
                results.append(f"{i}. {problem_name} (Not found)")
                print(f"   Not found")
            
            # Small delay to be respectful to the API
            time.sleep(0.1)
        
        # Write results to file
        with open('problem_links.md', 'w', encoding='utf-8') as f:
            f.write("<!-- filepath: d:\\Computing\\Competitive_Programming\\Codeforces\\Lists\\TLE_Eliminators\\1200\\a.md -->\n")
            f.write("# TLE Eliminators - 1200 Rated Problems\n\n")
            for result in results:
                f.write(result + "\n")
        
        print(f"\nResults saved to problem_links.md")
        
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    search_codeforces_problems()
