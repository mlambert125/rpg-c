print("main.lua")

local function countTo10()
    for i = 1, 10 do
        print(i)
    end
end

local message = "Hello from Lua!"
local pos = Position.new(1, 2)

print("Position: " .. pos:to_string())

print("x from lua: " .. pos.x)
pos.x = 3
print("x from lua after set: " .. pos.x)

print("Position after set: " .. pos:to_string())

pos.callback = function(self, x, y)
    print("callback from lua: " .. x .. ", " .. y)
    print("callback from lua: " .. self:to_string())
    print(message)
    countTo10()
end

return pos
