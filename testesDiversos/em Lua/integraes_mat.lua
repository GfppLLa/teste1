--[[
ponto medio integral
--]]
local function f(X)--funcao quadratica
    return X^2;
end

local function ponto_medio()
    local a=1;--limine inferior da integral
    local b =17;--limite superior da integral
    local n= 10000;--numero de subentervalos
    local h=(b-a)/n;
    local soma=0.0;
    for i=1, n do
        local x=a+((i-0.5)*h);
        soma=soma+f(x);
    end
    local integral =0.0
    integral=soma*h;
    print("Integral de f(x) = x^2 de", a, "a", b, "é aproximadamente", integral)

end
local function u(x)--define a subistituicao
    return math.sqrt(x);
end
local function du(x) --definindo a derivação da subistituição
    return 2*u(x)
end

local function integral(f, a, b, u, du)--integração com metodo da subistituição
    local resultado =0;
    local n=1000;
    local h=(u(b)-u(a))/n;
        for i=1, n do
            local u_i=(a)+(i-0.5)*h;
            local x_i=u_i^2;--
            resultado=resultado+f(x_i)*du(x_i)*h;
        end
        return resultado;
end

local function subistituicao()
   local a=1 --limites de a e b
   local b=4 --
    local resultado = integral(f, a, b, u, du);
    print("integral de f(x) = x^2 de ", a, "a", b, "é aproximadamente: ", resultado);
end
subistituicao();
--ponto_medio();

