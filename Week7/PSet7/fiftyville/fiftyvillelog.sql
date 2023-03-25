-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day=28 AND street ="Humphrey Street";

--Where and when the CS50 duck's theft took place

SELECT transcript
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

--Getting the list of the suspects

SELECT name
FROM people JOIN bakery_security_logs.license_plate = people.license_plate
WHERE year = 2021 and month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25
AND activity = "exit";

--Reducing the list of suspects according to the transcript of a witness on the ATM

SELECT name
FROM people JOIN bank_accounts ON bank_acounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";

--Getting name of the passengers from the earliest flight

SELECT NAME
from people JOIN passangers ON passangers.passport_number = people.passport_number
WHERE passangers.flight_id =
(SELECT id
FROM flights
WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id =
(
    SELECT id
    FROM flights
    WHERE city = "Fiftyville"
)
ORDER BY hour, minute
LIMIT 1);

--Finding out the name of the thief

SELECT name
FROM people JOIN phone_calls.caller = people.phone_number
WHERE year = 2021  AND month = 7 and day = 28 AND duration < 60;

--Destination where we left to

Select city
FROM airports
WHERE id =(
    SELECT destination_airport_id
    FROM flights
    WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = "Fiftyville"
    )
    ORDER BY hour, minute
    LIMIT 1);

--Finding out the accomplice

SELECT phone_number
FROM people
WHERE name = "Bruce";

-- (367) 555-5533

SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller = "(367) 555-5533");