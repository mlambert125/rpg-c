--- @meta _

--- @class Position
--- @field x number
--- @field y number
--- @field callback fun(self: Position, x: number, y: number)
--- @field new fun(x: number, y: number) : Position
--- @field to_string fun(self: Position) : string

--- @param x number
--- @param y number
--- @return Position
function make_position(x, y) end

--- @param pos Position
function print_position(pos) end

--- @type Position
Position = nil
