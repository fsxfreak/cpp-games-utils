# isabel-game
My version of my student's game. Teachers can learn too.

## notes
- should provide a feedback output for when a player successfully does an action

## design musings
- since everything needs to work with Item, why don't I create a repository of Items in the house or something
	- rooms can pull from available Items
	- doors can look at the UID of the Items
	- inject item UID or item into whatever room needed
	- all this opposed to storing items only in room, and exposing items to the world from a room
		- arguably a better real world model
		- or is the real world model like this
			- god creates all Items. god places items wherever he likes. god locks doors by referring to them, but not touching them after he places them.
- how to take my code, and create a sequential story out of it?
	- currently my code has the ability to manipulate the state of the world
	- but the GameState does not advance
	- implement -> win conditions, advance story conditions, triggering events when specific actions happen and stars align?

### representing items
- have one overall item class
- have item component classes that can be added into item that differentiate item
	- Item -> cosmetic, edible, unlocker, ingredient, etc
- for unlocker items
	- Generate unique id that matches item to a door

# License

To be added.

