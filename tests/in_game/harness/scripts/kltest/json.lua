local M = {}

local ESCAPES = {
    ["\\"] = "\\\\",
    ["\""] = "\\\"",
    ["\b"] = "\\b",
    ["\f"] = "\\f",
    ["\n"] = "\\n",
    ["\r"] = "\\r",
    ["\t"] = "\\t",
}

local function escape_char(c)
    return ESCAPES[c] or string.format("\\u%04x", string.byte(c))
end

local function is_array(tbl)
    local count = 0
    for k, _ in pairs(tbl) do
        if type(k) ~= "number" or k < 1 or math.floor(k) ~= k then
            return false, 0
        end
        count = count + 1
    end
    for i = 1, count do
        if tbl[i] == nil then
            return false, 0
        end
    end
    return true, count
end

local function encode_value(val, seen)
    local t = type(val)
    if val == nil then
        return "null"
    elseif t == "boolean" then
        return val and "true" or "false"
    elseif t == "number" then
        if val ~= val or val == math.huge or val == -math.huge then
            return "null"
        end
        return tostring(val)
    elseif t == "string" then
        return "\"" .. val:gsub('[%z\1-\31\\"]', escape_char) .. "\""
    elseif t == "table" then
        if seen[val] then
            error("kltest.json: cannot encode circular table")
        end
        seen[val] = true
        local arr, n = is_array(val)
        local parts = {}
        if arr then
            for i = 1, n do
                parts[i] = encode_value(val[i], seen)
            end
            seen[val] = nil
            return "[" .. table.concat(parts, ",") .. "]"
        else
            local keys = {}
            for k, _ in pairs(val) do
                if type(k) == "string" then
                    keys[#keys + 1] = k
                end
            end
            table.sort(keys)
            for i = 1, #keys do
                local k = keys[i]
                parts[#parts + 1] = encode_value(k, seen) .. ":" .. encode_value(val[k], seen)
            end
            seen[val] = nil
            return "{" .. table.concat(parts, ",") .. "}"
        end
    else
        return encode_value(tostring(val), seen)
    end
end

function M.encode(value)
    return encode_value(value, {})
end

return M

