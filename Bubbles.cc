local NeverLose = loadstring(game:HttpGet("https://raw.githubusercontent.com/4lpaca-pin/NeverLose/refs/heads/main/source.luau"))()

local Notification = NeverLose:CreateNotification()
local Watermark = nil

local function createMenu()
    local window = NeverLose:CreateWindow({
        Logo = "rbxassetid://120681281047173",
        Name = "Bubbles.cc",
        Content = "South-London",
        Size = NeverLose.Scales.Default,
        ConfigFolder = "BubblesCCConfigs",
        Enable3DRenderer = false,
    })

    Watermark = window:Watermark()

    Notification.new({ Title = "Welcome", Content = "Enjoy Bubbles!", Duration = 5 })
    Notification.new({ Title = "Discord", Content = "@5nz3 For Menus", Duration = 10 })
    Notification.new({ Title = "Devs", Content = "@5nz3 @fryedyoass", Duration = 15 })

    local mainTab = window:AddTab({ Name = "Main", Icon = "rbxassetid://10734950309" })

    local mainLeft = mainTab:AddSection({ Name = "Main Features", Position = "left" })
    local mainRight = mainTab:AddSection({ Name = "Combat", Position = "right" })

    mainLeft:AddLabel("Welcome to Bubbles.cc", true)
    mainLeft:AddToggle({ Name = "Master Switch", Default = true, Flag = "MasterSwitch", Callback = print })

    mainLeft:AddSlider({
        Name = "Test Slider",
        Min = 0,
        Max = 100,
        Default = 50,
        Rounding = 0,
        Flag = "TestSlider",
        Callback = function(v) print("Slider:", v) end
    })

    mainRight:AddToggle({ Name = "Aimbot", Default = false, Flag = "Aimbot", Callback = print })

    Watermark:SetRender(true)

    task.spawn(function()
        while true do
            task.wait(3)
            Watermark:SetRender(true)
        end
    end)
end

local function createIntro()
    local player = game.Players.LocalPlayer
    local playerGui = player:WaitForChild("PlayerGui")

    local introGui = Instance.new("ScreenGui")
    introGui.Name = "BubblesIntro"
    introGui.ResetOnSpawn = false
    introGui.Parent = playerGui

    local frame = Instance.new("Frame")
    frame.Size = UDim2.new(0, 420, 0, 280)
    frame.Position = UDim2.new(0.5, -210, 0.5, -140)
    frame.BackgroundColor3 = Color3.fromRGB(20, 20, 25)
    frame.BorderSizePixel = 0
    frame.Parent = introGui

    local corner = Instance.new("UICorner")
    corner.CornerRadius = UDim.new(0, 12)
    corner.Parent = frame

    local logo = Instance.new("ImageLabel")
    logo.Size = UDim2.new(0, 120, 0, 120)
    logo.Position = UDim2.new(0.5, -60, 0, 30)
    logo.BackgroundTransparency = 1
    logo.Image = "rbxassetid://120681281047173"
    logo.Parent = frame

    local title = Instance.new("TextLabel")
    title.Size = UDim2.new(1, 0, 0, 40)
    title.Position = UDim2.new(0, 0, 0, 160)
    title.BackgroundTransparency = 1
    title.Text = "Bubbles.cc"
    title.TextColor3 = Color3.fromRGB(255, 255, 255)
    title.TextScaled = true
    title.Font = Enum.Font.GothamBold
    title.Parent = frame

    local diveBtn = Instance.new("TextButton")
    diveBtn.Size = UDim2.new(0, 200, 0, 50)
    diveBtn.Position = UDim2.new(0.5, -100, 0, 210)
    diveBtn.BackgroundColor3 = Color3.fromRGB(0, 170, 255)
    diveBtn.Text = "DIVE IN"
    diveBtn.TextColor3 = Color3.new(1, 1, 1)
    diveBtn.TextScaled = true
    diveBtn.Font = Enum.Font.GothamBold
    diveBtn.Parent = frame

    local btnCorner = Instance.new("UICorner")
    btnCorner.CornerRadius = UDim.new(0, 10)
    btnCorner.Parent = diveBtn

    diveBtn.MouseButton1Click:Connect(function()
        introGui:Destroy()
        createMenu()
    end)
end

createIntro()