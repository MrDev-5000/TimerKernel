# ⏱️ TimerKernel

>TimerKernel is a lightweight Arduino library for managing non-blocking timers

---

## 🚀 Features

- Non-Blocking, No `delay()`, for best code responsiveness
- Support for multiple time units (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`)
- Multiple independent timers can be used simultaneously
- Simple and intuitive API
- Supports Floating Point duration for ease of use and percise timing

## ⚙️ Installation

To install this library:

1. **Download ZIP**  
   Click the green `Code` button on this repository page, then select "Download ZIP".

2. **Open Arduino IDE**  
   Launch the Arduino IDE on your computer.

3. **Install ZIP Library**  
   - Go to **Sketch > Include Library > Add .ZIP Library...**
   - Navigate to where you downloaded the ZIP file.
   - Select the ZIP file and click **Open**.

4. **Done!**  
   The library is now installed and ready to use. You can find examples for this library in **File > Examples > TimerKernel**.

>**Note:**
>
> - Do **not** unzip the downloaded file before installing.  
> - If you are updating an existing library, delete the old version from your `libraries` folder first.

## 🛠️ Usage

Traditionally, using `millis()` for timed events requires manual tracking of multiple variables:

```cpp
unsigned long previousMillis_1 = 0; //store time for first event
unsigned long previousMillis_2 = 0; //store time for second event

const long interval_1 = 1000; //interval for first event
const long interval_2 = 2000; //interval for second event


void setup(){

}

void loop() {

//check time since program started, and store in "currentMillis"
unsigned long currentMillis = millis();

   //conditional that checks whether 1 second has passed since last event
   if (currentMillis - previousMillis_1 >= interval_1) {
        previousMillis_1 = millis();
        //execute a piece of code, every *1 second*
   }

   //conditional that checks whether 2 seconds have passed since last event
   if (currentMillis - previousMillis_2 >= interval_2) {
        previousMillis_2 = millis();
        //execute a piece of code, every *2 seconds*
   }
}
```

With TimerKernel, this becomes much simpler and easier to manage:

```cpp
#include <TimerKernel.h>

TimerKernel timer_1;
TimerKernel timer_2;

const long interval_1 = 1000; //interval for first event
const long interval_2 = 2000; //interval for second event


void setup(){

}

void loop() {

   //conditional that checks whether 1 second has passed since last event
   if (timer_1.hasExpired(interval_1)) {
       //execute a piece of code, every *1 second*
   }

   //conditional that checks whether 2 seconds have passed since last event
   if (timer_2.hasExpired(interval_2)) {
       //execute a piece of code, every *2 seconds*
   }
}
```

## 📖 Examples

- [simple_led_blink](examples/simple_led_blink/simple_led_blink.ino) - demonstrates how to use the `toggleState()` to blink a led.

## 📚 API Reference

### `hasExpired()`

```cpp
  bool hasExpired(double duration, TimeUnit unit = MILLISECOND);
```

Checks whether the specified time duration has passed.
By default, the duration is expressed in milliseconds.

| Parameter  | Type     | Description                                                  |
| :--------  | :------- | :----------------------------------------------------------- |
| `duration` | `double` | Time interval in desired unit                                |
| `unit`     | `enum`   | Time unit (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`) |

**Returns:**

- `true` if the time duration has elapsed, otherwise it returns `false`.

---

### `toggleState()`

```cpp
  bool toggleState(double duration, TimeUnit unit = MILLISECOND);
```

Toggles state every time the duration elapses.
By default, the duration is expressed in milliseconds.

| Parameter  | Type     | Description                                                  |
| :--------  | :------- | :----------------------------------------------------------- |
| `duration` | `double` | Time interval in desired unit                                |
| `unit`     | `enum`   | Time unit (`MINUTE`, `SECOND`, `MILLISECOND`, `MICROSECOND`) |

**Returns:**

- The toggled state (`true` or `false`).

---

### `resetTimer()`

```cpp
  void resetTimer();
```

Resets both `hasExpired()` and `toggleState()`, so they start counting from zero.

**Returns:**

- Nothing

## 📜 License

- This project is licensed under the [MIT License](LICENSE).
