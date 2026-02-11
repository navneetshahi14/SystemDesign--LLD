import os

def create_structure():
    # Ask user for names
    topic = input("Enter Topic name: ").strip()
    subtopic = input("Enter SubTopic name: ").strip()

    # Base path
    base_path = os.path.join(topic, subtopic)

    # Folder paths
    cpp_folder = os.path.join(base_path, "C++")
    ts_folder = os.path.join(base_path, "Typescript")

    # Create directories
    os.makedirs(cpp_folder, exist_ok=True)
    os.makedirs(ts_folder, exist_ok=True)

    # File paths
    cpp_file = os.path.join(cpp_folder, f"{subtopic}.cpp")
    ts_file = os.path.join(ts_folder, f"{subtopic}.ts")

    # Create empty files if they don't exist
    open(cpp_file, "a").close()
    open(ts_file, "a").close()

    print("\n✅ Folder structure created successfully!")
    print(f"Created: {cpp_file}")
    print(f"Created: {ts_file}")


if __name__ == "__main__":
    create_structure()
