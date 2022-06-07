import pyautogui
import time

print(pyautogui.size())
while True:
    pyautogui.click(x=1638, y=520, button='left')
    time.sleep(3)
    pyautogui.click(x=1273, y=278, button='left')
    time.sleep(5)
