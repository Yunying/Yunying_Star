#Game: Catching Stars

##Game Interface
![My Game Interface] (http://ww4.sinaimg.cn/large/6fb2ab4dgw1e3ujrs3yj8j.jpg "Final Game")

##Explanation of the game interface
1.  **Girl**
	The player can use the keyboard(left, right) to control the little girl.
	The girl should collect as many `Star` and `Moon` as possible. The `Score` will increase everytime the `Girl` collides with the `Star`.
	Meanwhile, she must avoid `Car` and `BlackStar`.

2.  **Star**
	The stars will drop from the top of the screen.
	Different colors(Yellow, Blue, Green, Red) will appear randomly.
	Each star worths 20 or -20(Green) points.
	If the `Girl` does not collect them, they will disappear after they go out of window.

3. **BlackStar**
	`BlackStar` is like a bomb.
	It will randomly move in the window for 5 seconds. 
	The player must use a `Mouse` to click it in 5 seconds. After clicking, it will disappear.
	After 5 seconds, the `BlackStar` will explode and the girl will lose a life.

4. **Car**
	The `Car` will appear from the left of the window with a pre-determined time interval.
	It will move horizontally. The player has to press `Space` to make the `Girl` jump to avoid the car.
	If not jump, the girl will lose 300 points.
	When points is below, she will lose a life.

5. **Moon**
	The `Moon` will move down from top of the window.
	It will stop above the girl for 2 seconds, and then move upward again.
	During that two seconds, the girl can jump to reach the moon.
	She will get an extra life if she reaches the moon. (3 lives maximum)

##Rules Summary
####Game Control
1. Keyboard: left, right, space(jump to avoid the car or to reach the moon)

2. Mouse: To click on the Black Star to avoid it from exploding

####Score and Life Calculation
1. When the game starts, the player has three lives
   When the number of lives reaches zero, game over.

2. Each `Star` worths _20_ points. Each Green `Star` worths _-20_ points.
   The score will increase/decrease when the girl collides with the star

3. The `Car` worths _-300_ points
   The score will decrease when the girl collides with the car
   
   If the score decreases to below zero after the deduction, a life will be lost.
   The score will be zero. (`Score` is an unsigned int)

4. When the `BlackStar` explodes, the player loses a life.
   Score remains the same.

5. When the player gets a `Moon`, she gets an extra life.
   If the player still has three lives, she gets no extra life but 1000 extra points.

####Difficulty
Game difficulty will increase as time moves on:
1. The speed of the dropping star will increase
2. `Car` and `BlackStar` will appear more frequently

##User Interface
![UserInterFace](http://ww1.sinaimg.cn/bmiddle/6fb2ab4dgw1e3uludgkoxj.jpg "UserInterface")
	
	
