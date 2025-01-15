# EXPLANATION_FOR_ARDUINO

This code reads the value of a potentiometer and generates sounds using a piezo buzzer based on the potentiometer's position. Below is a detailed explanation:

---

### Code Breakdown:

#### 1. **Variable Declarations:**
```cpp
int potenciometro = A0; // Analog pin where the potentiometer is connected.
int valor;             // Variable to store the raw analog reading from the potentiometer.
int posicion;          // Variable to store the scaled position of the potentiometer.
int bocina = 2;        // Digital pin connected to the piezo buzzer.
```

#### 2. **Setup Function:**
```cpp
void setup()
{
  pinMode(bocina, OUTPUT); // Configures the buzzer pin as an output.
  Serial.begin(9600);      // Initializes serial communication at 9600 baud rate.
}
```
- **`pinMode(bocina, OUTPUT)`** ensures the buzzer pin can send signals.
- **`Serial.begin(9600)`** sets up communication with the serial monitor for debugging.

#### 3. **Main Loop:**
```cpp
void loop()
{
 valor = analogRead(potenciometro); // Reads the potentiometer's analog value (0–1023).
 posicion = map(valor, 0, 1023, 0, 100); // Scales the value to a range of 0–100.
 Serial.begin(posicion); // (Error: This line incorrectly attempts to reinitialize Serial communication. Remove it.)
 delay(100);
 Serial.println(posicion); // Prints the scaled position to the Serial Monitor.
 delay(1000);
```
- **`analogRead(potenciometro)`** gets the current voltage from the potentiometer.
- **`map(valor, 0, 1023, 0, 100)`** converts the range 0–1023 (raw reading) to 0–100 (scaled percentage).
- **`Serial.println(posicion)`** displays the scaled value for debugging.

---

#### 4. **Tone Generation:**
```cpp
if (posicion >= 0 and posicion <14){
 tone(bocina, 523.25, 500); // Generates a tone at 523.25 Hz (C note) for 500 ms.
 delay(500);                // Waits for 500 ms.
}
```
- **`tone(pin, frequency, duration)`** makes the buzzer generate a sound:
  - `pin`: Buzzer's digital pin.
  - `frequency`: The pitch of the tone in Hz.
  - `duration`: Duration of the sound in milliseconds.
- **`delay(500)`** ensures a pause between tones.

#### 5. **Frequency Mapping:**
- Based on the `posicion`, different tones are played. For example:
  - **0 to <14:** `523.25 Hz` (C note).
  - **14 to <28:** `587.33 Hz` (D note).
  - **28 to <42:** `659.26 Hz` (E note).
  - **42 to <56:** `698.46 Hz` (F note).
  - **56 to <70:** `783.99 Hz` (G note).
  - **70 to <84:** `880 Hz` (A note).
  - **84 to <98:** `987.77 Hz` (B note).

#### 6. **No Tone Condition:**
```cpp
else if (posicion >= 98 and posicion <101){
 noTone(bocina); // Stops any tone generation.
 delay(1000);    // Waits for 1 second.
}
```
- **`noTone(pin)`** stops the buzzer from making a sound.
---


### What It Does:
- **Reads a potentiometer's position.**
- **Maps the position to a specific frequency range.**
- **Generates corresponding musical notes using a piezo buzzer.**
- **Displays the potentiometer's scaled position on the serial monitor.**

