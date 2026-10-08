-- EXPECT-DIAGNOSTIC: need-check-nil
-- currentDialogue is intentionally nullable outside synchronous dialogue actions.

local dialogue = currentDialogue
dialogue:endDialogue(true)
