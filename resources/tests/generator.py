with open('finding.txt', 'w', encoding="utf-8") as file:
    letters = "QWERTYUIOPASDFGHJKLXCVBNM"
    for i in range(1, len(letters)):
        file.write(letters[i - 1] + "town\n")