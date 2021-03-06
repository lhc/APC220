-- Codigo para receber dados com ESP-01 via modulo APC220 para teste de campo

-- Certifica que o wifi esta desligado para economizar bateria
wifi.sta.disconnect()

-- Definicao dos pinos dos leds
led_vermelho = 4
led_verde = 3
--Definicao do estado dos leds
status_led_vermelho = gpio.LOW
status_led_verde = gpio.LOW
-- Inicializa LEDs apagados
gpio.mode(led_vermelho, gpio.OUTPUT)
gpio.write(led_vermelho, status_led_vermelho)
gpio.mode(led_verde, gpio.OUTPUT)
gpio.write(led_verde, status_led_verde)

function desliga_led_vermelho()
    gpio.write(led_vermelho, gpio.LOW)
end

function pisca_led_vermelho()
    gpio.write(led_vermelho, status_led_vermelho)
    if status_led_vermelho == gpio.LOW then
        status_led_vermelho = gpio.HIGH
    else
        status_led_vermelho = gpio.LOW
    end
end

tmr.alarm(0, 200, 1, pisca_led_vermelho)

-- Limpa variavel data antes de ler a serial
data = ""
uart.on("data", "#",
    function(data)
        print ("Recebido do APC220:", data)
        if (data=="LHC#") then
            tmr.stop(0)
            desliga_led_vermelho()
            status_led_verde = gpio.HIGH
            gpio.write(led_verde, status_led_verde)
            tmr.delay(1000000)
            status_led_verde = gpio.LOW
            gpio.write(led_verde, status_led_verde)
            tmr.alarm(0, 200, 1, pisca_led_vermelho)
        end
end, 0)
