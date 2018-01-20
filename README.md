# Grimly

1. Malloc error somewhere.
grimly(22279,0x7fffa6d5c340) malloc: *** error for object 0x7f8e5cc02938: incorrect checksum for freed object - object was probably modified after being freed.
2. It works for smaller cases, but sometimes it returns "MAP ERROR" when it's still correct. I'm assuming I'll need to check the validation and ensure that it's correct and that everything is being allocated. 
