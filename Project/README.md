This is a C++ Builder FMX application created in Embarcadero RAD Studio to **visualize and compare Linear Search and Binary Search algorithms** in a user-friendly, step-by-step interface.

## 🔍 Features

- Users can input a list of numbers (as strings).
- Visual step-by-step comparison of Linear and Binary search:
  - Search steps shown in colored **white boxes**.
  - Matched items highlighted. (if not, bug)
- Displays:
  - Time taken (in microseconds).
  - Number of steps for each algorithm.
  - Summary comparison.
- Scrollable result display using `TScrollBox`.

## 🧠 Concepts Visualized

- **Linear Search**: Scans each item one-by-one.
- **Binary Search**: Operates on a sorted copy of the list and divides the search space each time.

## 📦 Technologies Used

- Embarcadero RAD Studio
- C++ Builder FMX framework
- Visual components:
  - `TListBox`
  - `TEdit`
  - `TScrollBox`
  - `TPanel`, `TLabel`

## 📸 UI Preview

<img width="855" height="998" alt="image" src="https://github.com/user-attachments/assets/6ba1d52e-231b-4aac-a0ad-e2f5baef79db" />


## 🚀 How to Run

1. Open the `.cbproj` file in RAD Studio.
2. Build and run the application.
3. Enter numbers into the input box and press Enter.
4. Click the **Search** button to start visualization.

## 📁 File Structure

- `FinalProjectAssignment.cpp`: Main form
- `Unit2.cpp/h/fmx`: Visual logic and search implementation
- `__history/`: Backup by RAD Studio
- `.cbproj`: Project configuration

## 🧪 Example Input

10 20 30 40 50 60 70

Search for `60` and see how both algorithms handle it step by step.

## 📌 Notes

- Binary search uses a sorted **copy** of the list. Original input is untouched.
- If input cannot be converted to an integer, string comparison is used.

---

### 💻 Author
Faatin Nur Husna (22010085)  
Bachelor of Computer Engineering

---
