--[[
derivações f' ou dx
--]]

local function f(x) --funcao quadratica
    return x^2;
end

local function derivacao(f, x, h)
    local fxMaisH = f(x+h) --funcao quadratica de x +h
    local fxMenosH = f(x-h)--de x menos h
    local dividirP2 = (fxMaisH-fxMenosH)/(2*h) --fazer ou nao fazer funcao quadratica aqui, eis a questão
    return dividirP2;
end

local function main()
    local x= 3
    local h = 0.001
    local derivada =derivacao(f, x, h)
    print(" derivacao : ", derivada)
end
main()

--[[
funcoes f(x)
--]]
--função constante
local function fConstante(x,c)
    return c
end
local function constante()
    local x= 10; --valor de 
    local c= 7;--constante 
    print()
end

--função linear 
local function fLinear(x, a, b)
    return a*x+b;-- f(x)=a⋅x+b.
end

local function linear()
    local x = 5--valor de x
    local a= 2; --valor angular
    local b = 3; --coeficiente linear
    --imprimier
end

--função quadratica

local function fQuadratica(x, a, b, c)
    return a*(x^2)-(b*x)+c;--f(x)=a⋅x2−b⋅x+c  
end
local function quadratica()
    local x=3;--valor de x
    local a=2;--coeficiente do termo quadratico
    local b=4;--coeficiente do termo linear
    local c=1;--constante
    --saida
end

--função polinomial
local function fPolinomial(x, a, b ,c ,d)
    return (a*(x^3)) +(b*x^2)+(c*x)+d--f(x)=a⋅x3+b⋅x2+c⋅x+d.
end
local function polinomial ()
    local x = 2  -- valor de entrada para x
    local a = 3  -- coeficiente do termo cúbico
    local b = 2  -- coeficiente do termo quadrático
    local c = -5 -- coeficiente do termo linear
    local d = 4  -- termo constante
    --saida
end