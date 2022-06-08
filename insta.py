from selenium import webdriver
import time
from openpyxl import Workbook
import pandas as pd
from selenium.webdriver.common.keys import Keys

wb = Workbook(write_only=True)
ws = wb.create_sheet()

driver = webdriver.Chrome()
driver.get("https://www.instagram.com/")
driver.implicitly_wait(3)

# 로그인
driver.find_element_by_css_selector(
    "#loginForm > div > div:nth-child(1) > div > label > input").send_keys("01077234185")
driver.find_element_by_css_selector(
    "#loginForm > div > div:nth-child(2) > div > label > input").send_keys("Korea@12$$")
driver.find_element_by_css_selector(
    "#loginForm > div > div:nth-child(3) > button > div").click()
time.sleep(1)

# 팝업 종료
driver.find_element_by_css_selector(
    "#react-root > section > main > div > div > div > div > button").click()
driver.find_element_by_css_selector(
    "body > div.RnEpo.Yx5HN > div > div > div > div.mt3GC > button.aOOlW.HoLwm").click()
time.sleep(1)
