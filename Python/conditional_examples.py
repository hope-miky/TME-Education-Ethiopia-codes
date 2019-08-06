# Examples of if statements
# General format:
# if <condition is True>:
#     <code to execute if condition is True>
# else:
#     <code to execute if condition is False>
if 9 > 5:
    print ("Yes, 9 greater than 5")

if 9 != 5:
    print ("Yes, 9 not equal to 5")

# An example using "not" and "and" keywords
if not (10 == 4) and 9 > 5:
    print ("Yay, basic math competency achieved!")
else:
    print (":(")

# Traffic light example
light_color = input("What color is the traffic light? ")
light_color = light_color.lower()
print (light_color, "?")
if light_color == "red":
    print ("You should stop")
elif light_color == "yellow":
    print ("Slow down!")
elif light_color == "green":
    print ("Go ahead!")
else:
    print ("Really? What country are you in??")
