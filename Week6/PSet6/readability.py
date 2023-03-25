Text = input("Text: ")

letters = words = sentences = 0

for char in Text:
    if char.isalpha():
        letters += 1
    if char.isspace():
        words += 1
    if char in ['?', '.', '!']:
        sentences += 1

words += 1

L = (letters * 100) / words
S = (sentences * 100) / words
result = int((0.0588 * L - 0.296 * S - 15.8) + 0.5)

if result < 1:
    print('Before Grade 1')
elif result >= 16:
    print('Grade 16+')
else:
    print(f"Grade {result}")