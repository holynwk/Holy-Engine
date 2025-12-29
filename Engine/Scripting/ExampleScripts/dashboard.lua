function onTick(dt)
    local speed = vehicle:getSpeedKmh()
    if speed > 60 then
        vehicle:setLights(true)
    end
end
