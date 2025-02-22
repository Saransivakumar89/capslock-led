# capslock-led

## 📌 Overview  
The **CapsLED Module** is a custom embedded system driver that controls the LED indicator for the Caps Lock key. This module monitors the keyboard state and toggles the LED based on the Caps Lock status.  

## ⚙️ Features  
- Monitors Caps Lock state in real-time  
- Controls LED to indicate Caps Lock ON/OFF status  
- Works with Linux-based systems  
- Designed for integration with keyboard drivers  

## 🏗️ Installation & Setup  
### 1️⃣ **Clone the Repository**  
```bash
git clone https://github.com/your-username/capsled-module.git
cd capsled-module

###2️⃣ **Build the Module**
`make`

###3️⃣ **Load the Module**

`sudo insmod capsled.ko`

###4️⃣ **Check if the Module is Loaded**

`lsmod | grep capsled`

###5️⃣ **Unload the Module **

`sudo rmmod capsled.ko`



