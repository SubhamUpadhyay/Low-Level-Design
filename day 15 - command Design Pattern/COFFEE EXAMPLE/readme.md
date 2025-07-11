COMMAND DESIGN PATTERN
    


    🧃 Real-Life: Coffee Machine Buttons


Imagine a coffee machine with two buttons:

☕ Make Coffee

❌ Cancel Order

We’ll use the Command Pattern to encapsulate the MakeCoffeeCommand so the machine doesn’t need to know how coffee is made—just that when a button is pressed, the right command is executed.



✅ Goal
Decouple the button press (invoker) from the actual coffee-making logic (receiver).

