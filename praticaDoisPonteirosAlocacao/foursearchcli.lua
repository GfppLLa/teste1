--[[
todo: 
question four
get arguments from terminal
assign arguments to array
read s to search in the array
mark all the occurences of the s number 
mark the first occurence of the s number

    5.print the table with the marks of the serach, or if thers no occurences
    4.ask in terminal for s to search
    3.
    2.make the assignment from args to array
    1.main receive arguments
--]]
local function setTextColor(color)
    local colors = {
        reset = "\27[0m",
        red = "\27[31m",
        green = "\27[32m",
        yellow = "\27[33m",
        blue = "\27[34m",
        magenta = "\27[35m",
        cyan = "\27[36m",
        white = "\27[37m"
    }
    return colors[color] or colors.reset
end
local tableMethods={
    __newindex=function(table, index, content)
        --if type(index)~="string" then--key or index, its more readable
          --  error(print(setTextColor("red").."the index must be a string"..setTextColor("reset")))
        --end
        if type(content)~="number" then
            error(print(setTextColor("red").."the content must be a number"..setTextColor("reset")))
        end
        rawset(table, index, content) --forces the value to the end of the table
    end,
    __index=function (table, index) --
        if rawget(table, index) ==nil then
           --if the rawset didnt work this part will make another rawset adding a table at the end of 
           --the originla
           rawset(table, index, {})
        end
        return rawget(table, index);
        
    end
}
local function putsArray (numberArray, controlArray)
    print("array list")
    local control=0
    for i =1, controlArray[1] do--put above the first occurence of the number some mark to indicate that
        io.write(" ")
            if numberArray[i]==controlArray[2] and control~=1 then
                io.write(" 1º")
                control=1
            else
                if numberArray[i]~=controlArray[2] then
                    io.write(" ")
                end
            end
    end
    io.write("\n")
    for i =1, controlArray[1] do--put in terminal the array, number by number
        io.write(" ")
            if numberArray[i]==controlArray[2] then
                io.write("[",numberArray[i],"]")
            else
                io.write(numberArray[i])
            end
    end
    io.write("\n")
end
local function main()
    local arrayNumber=setmetatable({},tableMethods)
    local controlArray=setmetatable({}, tableMethods)
    controlArray[1]=0
        for i=1, #arg do
            arrayNumber[i]=0
            arrayNumber[i]=tonumber(arg[i])
            controlArray[1]=controlArray[1]+1
        end
        controlArray[2]=0
        print("insert the number to be find ")
        controlArray[2]=io.read("n")
    putsArray(arrayNumber, controlArray)
end
main()