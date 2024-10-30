 Lampada={}
Lampada.__index=Lampada
--classe lampada
function   Lampada:new()
    local self =setmetatable({}, Lampada)
    self.estado=false
    self.intensidade=0
    return self
end

function Lampada:getIntensidade()
return self.intensidade
end

function Lampada:isLigada()
return self.estado
end   

function Lampada:setIntensidade(intensidade)
self.intensidade =intensidade
end

function Lampada:setEstado(estado)
self.estado = estado
end

do
local lamp1=Lampada:new()
 --lamp1:setIntensidade(10)
local intensidade =lamp1:getIntensidade()
print("lamp1: ",intensidade)
end