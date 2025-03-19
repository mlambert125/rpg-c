return {
    name = "Overworld",
    tiles = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
    npcs = {
        {
            name = "man1",
            dialog = {
                "Hello, welcome to the overworld!",
                "This is a simple example of an NPC.",
                "You can add more dialog lines here."
            },
            starting_position = {x = 5, y = 5},
            characterSpriteIndex = 1,
            onConversationStart = function()
                print("NPC interacted with!")
            end,
            onConversationEnd = function()
                print("Conversation ended.")
            end
        },
    },
    onEnter = function()
        print("Entered the overworld!")
    end,
    onExit = function()
        print("Exiting the overworld.")
    end,
    onTileEnter = function(x, y)
        print("Entered tile at position: (" .. x .. ", " .. y .. ")")
        if math.random() < 0.1 then
            print("Encountered a wild monster!")
            -- Create encounter with callbacks, etc.
        end
    end,
    onTileExit = function(x, y)
        print("Exited tile at position: (" .. x .. ", " .. y .. ")")
    end,
}

