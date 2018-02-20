



        |l|
        |l| 
~~~~|T| |T|T|M|M|M|
~~|M| |M|
     
                  
        ll           /
        ll  #      o /
~~~~TT  TTTTMMMMMMMMMMMM
~~MM  MM


->player is represented by "o"
  blocks are represented by 2 contiguous letters (stone : "MM", dirt : "TT", water : "~~", tree trunk (wood log) : "ll" etc.)
  (?) (wouldn't it be better if it was one wide, since you can scale down into one sized blocks)
  you can mine blocks (takes a certain time, fade the block letters to black as you do it)
  there are enemies ("#" is a possible one)
  <!> you can scale down into a block (represented by a letter (one of them (the one youre standing on) if theres 2)) :
  (player is here | )
                  v

|X|X|X|X|X|X|X|                                             |X|X|X|X|X|X|X|
|X|X|X|X|X|X|X|X| o                                       |X|X|X|X|X|X|X|X|
|X|X|X|X|X|X|X|X|X|                                     |X|X|X|X|X|X|X|X|X|
|X|X|X|X|X|X|X|X|X|X|                                 |X|X|X|X|X|X|X|X|X|X|
|X|X|X|X|   |X|X|X|X|X|                             |X|X|X|X|X|   |X|X|X|X|
|X|X|X|X|     |X|X|X|X|X|                         |X|X|X|X|       |X|X|X|X|
|X|X|X|X|       |X|X|X|X|X|X|                 |X|X|X|X|X|         |X|X|X|X|
|X|X|X|X|         |X|X|X|X|X|X|X|         |X|X|X|X|X|X|           |X|X|X|X|
|X|X|X|X|           |X|X|X|X|X|X|X|X| |X|X|X|X|X|X|X|             |X|X|X|X|
|X|X|X|X|             |X|X|X|X|X|X|X|X|X|X|X|X|X|X|               |X|X|X|X|
|X|X|X|X|               |X|X|X|X|X|X|X|X|X|X|X|X|                 |X|X|X|X|
|X|X|X|X|                 |X|X|X|X|X|X|X|X|X|X|                   |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|
|X|X|X|X|                                                         |X|X|X|X|


scaling down makes the player able to collect other ressources, find other things etc
contrary to what is represented above, scaled up versions of blocks (letters) are irregular in shape, in composition of blocks etc.

each scale (normal world, scaled up versions of normal world blocks, scaled up versions of blocks of scaled up versions of normal world blocks, etc.) has a different graphic style that identifies it. For example -1 scale (below normal world scale) blocks are like that : "|X|" while normal world blocks are just letters
maybe also other physics laws, things happening like floating things, hanging things etc bizarre stuff that make (it) you feel like (it is) you really come in another world

another cool mechanic could be that you can modify a block at the scale below in order to change its appearance/properties in the current scale
ex : maybe recognize the shape to make another letter
      -> you scale down into a "M" block, you mine its sub-level blocks (the "|X|"), rearrange them to form a "N" letter (good enough to be recognisable) and when you come back to the above scale (here normal world, it is now a "N" block). 
        (?)(but then what if you make a block take the form of "?" -> Id say, elements (=block types) are only letters, you can modify a block to become any other block type, or maybe enemies "#" and other npc "o" and other things but not "?" and other reserved characters)A block that is not recognisable to any shape would become a ?
        -> each letter (block type) could be an "element" having its own properties, uses ...
           scaling down into a block of a certain type could be a way to obtain a block of any type (including an "o" (another player (or npc))), by modifying its structure
            -> at the below scale, contrary to what is displayed above with the M, blocks making a block type could be different, there could be of multiple types, arranged randomly or not.
                (?)(2) but then, do you need to get the exact composition of sub blocks of a block type to make it from another one ? That would make it even more difficult to modify blocks
                    -> could have a device to inject some sublevel blocks into a block to make it a valid block type. You would get those sublevel blocks with another device to wich you could feed a block to get all its sublevel blocks
            -> as this would be very tedious, some tools could be aquired to mine quicker, then maybe mass edit (square, defined rectangles, lines, circle, etc) and maybe eventually to apply a pattern, program (in a real programming lg) a quarry (yes !)  (or something)
      
going down in scale can be done by finding objects in the current scale (and maybe combined with objects of greater scales)

there are different ennemies in each scale

enemies can pursue the player through scales but they remain their original size  (maybe by scaling down too for some of them), they are huge (the size of the scaled down block) and move very slowly.
they eat up the current scaled up block as they pursue the player, and this could be a way to modify big chunks of the block quickly although not precisely at all

<!> you can mine blocks (at their scale) you previously modified (at the scale below)
      -> you could have a device to make set difference union, etc of 2 mined blocks, to speed up the editing process
it could become basically an ascii art editor,
Questions :
    
    - does each block type (=letter) appear in a specific scale
        it must be that way
    - solve (?)(2)
        kinda done

Issues : 
  
    - you would spend all this time modifying blocks at a sublevel, it would be complex and tedious but when you go back to normal world you only get a single block and you think "all of this for THAT"
        -> modifying blocks at a sublevel should allow you to modify above level more easily, give you grater powers in the above world
            -> there should be worlds above the normal world, with a top world (level) being the god world (with only "G" (god) and "D" (godess) blocks)(sounds cheesy I know)
            -> the bottom world should be blocks composed with nothing (?)
                -> basically if b is bottom level b should be many . forming b+1 type blocks, then if you scale down into a . you get a single ., and if you dive into that then nothing (?) or you cant (yeah, better solution). you get in top of that . and if you fall, you die (haha)

