local M = {}

local function describe(value)
    if type(value) == "string" then
        return string.format("%q", value)
    end
    return tostring(value)
end

function M.describe(value)
    return describe(value)
end

function M.assert_true(condition, message)
    if not condition then
        error(message or "assert_true failed", 2)
    end
end

function M.assert_equal(actual, expected, label)
    if actual ~= expected then
        local prefix = label and (label .. ": ") or ""
        error(string.format("%sexpected %s, got %s", prefix, describe(expected), describe(actual)), 2)
    end
end

function M.assert_nil(actual, label)
    if actual ~= nil then
        local prefix = label and (label .. ": ") or ""
        error(string.format("%sexpected nil, got %s", prefix, describe(actual)), 2)
    end
end

function M.assert_not_nil(actual, label)
    if actual == nil then
        local prefix = label and (label .. ": ") or ""
        error(string.format("%sexpected non-nil value, got nil", prefix), 2)
    end
end

function M.assert_near(actual, expected, tolerance, label)
    local tol = tolerance or 1e-6
    if type(actual) ~= "number" or type(expected) ~= "number" or math.abs(actual - expected) > tol then
        local prefix = label and (label .. ": ") or ""
        error(string.format("%sexpected %s +/- %s, got %s", prefix, tostring(expected), tostring(tol), describe(actual)), 2)
    end
end

function M.assert_match(actual, substring, label)
    local text = tostring(actual or "")
    local needle = tostring(substring or "")
    if text:find(needle, 1, true) == nil then
        local prefix = label and (label .. ": ") or ""
        error(string.format("%sexpected %s to contain %s", prefix, describe(text), describe(needle)), 2)
    end
end

return M


