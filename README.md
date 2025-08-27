# 🚗 Toyota Mechanical Innovation Challenge – AGV Design (KAIZENBERGER)

KAIZENBERGER is an **automated guided vehicle** (AGV) design for the **Toyota Mechanical Innovation Challenge**. This challenge, hosted by Toyota Motor Manufacturing Canada (TMMC), involved designing and presenting an AGV capable of safely transporting car doors and boxes within a simulated factory setting.

## 📌 Challenge Overview
We are tasked with developing a mechanical system that can:
- 🛻 **Pick up and move car doors** from a 5-inch-tall shelf to a designated location.
- 📦 **Pick up and move boxes** from a 10-inch-tall shelf to the ground.
- 🔄 Efficiently switch between "door-moving" and "box-moving" modes.
- 🚗 Navigate forward, backward, and around corners.
- 💸 Optimize for speed, cost, safety, and ease of use.

## 🧱 System Requirements & Constraints
- Must not damage parts during transport/handling.
- Must be able to operate safely in a warehouse environment.
- Mechanisms must mount to a Tetrix base using 8 screws (maximum).
- Must be built with the given materials and a maximum of two 3D printed parts (=< 27 cm^3)

## 🧰 Materials Used
- 1 **Tetrix Prizm Microcontroller**
- 1 **Tetrix Max kit** (Hardware kit)
- 1 **TeleOp Module**
- 2 **Custom 3D Printed Components** (Gripper)
- 1 **Ultrasonic Sensor** (Human & Obstacle Detector) 
- 1 **DC Motor with Encoder** (Arm Lifting Mechanism) 
- 2 Servos (Arm Lifting Mechanism)
- 1 Battery (12V)
- 1 PS4 Controller
- 1 Pre-Made Four Wheel Tetrix Base

## 🔍 Project Preview 

### 🏗️ Crane Mechanism Inspiration Video

[![Watch on YouTube](https://img.youtube.com/vi/T3MieUvsxxU/0.jpg)](https://youtu.be/T3MieUvsxxU)

<img width="718" height="406" alt="image" src="https://github.com/user-attachments/assets/7e17bcc5-e30a-4387-a861-99d5ff96f1f5" />

### 🎬 Early Testing in Action

Check out an early-stage demo of our AGV system during development and testing:

[🔗 Watch the video](https://github.com/user-attachments/assets/0cc993b4-1a04-4319-93ec-2eacf7249065)

## ⚙️ How it Works 
### Movement
The AGV is controlled by the PS4 controller, with different buttons corresponding with different functions
### Picking up Products
It switches between modes to handle car doors and boxes safely and efficiently using the gripper and lifting arm

## 🛠 Components 

### Gripper
The gripper was redesigned in SolidWorks and enhanced with custom 3D printed extensions to improve grip and accommodate both doors and boxes.

Mounted on the Tetrix base, it integrates seamlessly with the motor and servo arm mechanisms to allow precise, reliable handling.

![image](https://github.com/user-attachments/assets/f78ac7f2-cae5-4efd-8a4e-7ab6ec7f24ea)

Top Left: The modified gripper with our 3D printed extensions   
Bottom Left: The original Tetrix gripper

## ⚠️ Challenges: 
- Effectively managing project timelines and prioritizing tasks to meet deadlines despite unexpected technical challenges

- Designing a gripper flexible enough to securely handle parts of different shapes and sizes within material constraints

- Debugging the interaction between mechanical components and motor controls for smooth operation

- Balancing cost, safety, and performance under strict design limitations

- Managing limited 3D printed part volume while maintaining durability and functionality
  
## 🚀 Next Steps: 
- Improve autonomous navigation using sensor integration for obstacle avoidance

- Optimize the gripper design for faster mode switching and enhanced grip

- Implement more advanced control logic for adaptive handling based on part type










