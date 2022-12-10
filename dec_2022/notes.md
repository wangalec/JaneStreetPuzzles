Approach

Using a dice class to keep track of all the faces when tipped onto a new square
Brute force testing different values on the dice by iterating through all possible values of a dice in a certain range and going through the grid with that die. 
When the final square is reached, return a vector of the squares moved through

Limitations

This could get dicey (haha) if the numbers were larger. Luckily the highest number is 9 so this brute force method is doable. However, if numbers were much higher, other approaches would be needed to constrain the possible faces of the die. 