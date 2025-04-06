# Informatyka-2021
Poprawiony projekt z informatyki z lat 2021

# 🎮 Shape Shooter

## 📌 Description  
**Shape Shooter** is a dynamic 2D shooting game created in **C++** using the **SFML** multimedia library.  
The player pilots a flying object that must avoid and destroy falling shapes.  
Each destroyed shape adds to the player's score, while any missed or colliding shape results in lost health.  
The game ends when the player's lives run out.

---

## 🧰 Technologies Used  
- **C++**  
- **SFML (Simple and Fast Multimedia Library)**  
- **Visual Studio** (for development and compilation)  

---

## 🚀 Features  
- 🔹 Real-time movement using **WASD keys**  
- 🔹 Randomly falling geometric shapes as enemies  
- 🔹 Shooting mechanic with score tracking  
- 🔹 Life/health system and game over state  
- 🔹 Simple 2D graphics rendered with SFML  
- 🔹 In-game help screen (**F1**)  
- 🔹 Ability to save your score (**Y** key)  

---

## 🕹️ Controls  
| Key        | Action                          |
|------------|----------------------------------|
| W / A / S / D | Move the player object        |
| Spacebar   | Shoot bullet                   |
| F1         | Show controls/help screen      |
| Y          | Save the current score         |
| Esc        | Quit the game                  |

---


## 🏁 How to Run the Game

Follow these steps to get the game up and running:

1. **Clone the repository:**
   bash
   git clone https://github.com/185755/Informatyka-2021.git
   cd shape-shooter
2. **Navigate to the solution file**:  
   Go to the following path in your project folder:  
   `Informatyka-2021\Inf_Gra_Corrected\informatyka_2021_projekt-main\ConsoleApplication1`

3. **Open the `.sln` file**:  
   Open the `ConsoleApplication1.sln` file in **Visual Studio**.

4. **Build the project**:  
   In Visual Studio, select the correct configuration (e.g., `Release` or `Debug`, `x64`), and click on **Build** > **Build Solution**.

5. **Launch the game**:  
   After the build completes, the game should start automatically. A menu will appear with the following options:  
   - **Start Game**  
   - **Check High Scores**  
   - **Options**  
   - **Hard Mode**

6. **In the game**:  
   - **Control the player**: Use the **WASD keys** to move the player object.
   - **Shoot**: Press the **Spacebar** to shoot.
   - **Health**: Avoid falling shapes or destroy them before they reach you. If shapes pass by or hit you, you lose health.
   - **Points**: Destroying shapes gives you points.
   
 ---
## ⚠️ SFML Configuration Issues

If you encounter issues setting up SFML or linking it with your project, don't worry! This is a common problem, especially when working with external libraries like SFML.

Here’s a helpful YouTube tutorial that walks you through the setup process step by step:

🔗 [SFML Setup Tutorial](https://www.youtube.com/watch?v=A5tXaXa_Tss)

Following this guide should help you resolve any configuration issues and get the game running smoothly.
