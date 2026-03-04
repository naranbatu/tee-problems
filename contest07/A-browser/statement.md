# A. Веб хөтөч

## Бодлого

Веб хөтчийн **back** ба **forward** товч хэрхэн ажилладагийг загварчил. Дараах үйлдлүүдийг дэмжих ёстой:

- **VISIT url** — Шинэ хуудас руу зочилно. Forward түүхийг арилгана.
- **BACK** — Өмнөх хуудас руу буцна. Хэрэв буцах боломжгүй бол **"IGNORE"** гэж хэвлэ.
- **FORWARD** — Дараагийн хуудас руу явна. Хэрэв урагшлах боломжгүй бол **"IGNORE"** гэж хэвлэ.
- **CURRENT** — Одоогийн хуудсыг хэвлэ.

Анхны хуудас нь **"home"** юм.

## Оролт

Эхний мөрөнд **Q** — үйлдлийн тоо.

Дараагийн **Q** мөр бүрд нэг үйлдэл.

## Гаралт

BACK (амжилттай), FORWARD (амжилттай), CURRENT үйлдэл бүрд одоогийн хуудсыг хэвлэ. BACK/FORWARD боломжгүй бол **"IGNORE"** хэвлэ.

## Хязгаарлалт

- Цагийн хязгаар: **1 секунд**
- Санах ойн хязгаар: **256 MB**

## Subtask

| Subtask | Оноо | Нөхцөл |
|---------|-------|--------|
| 1 | 30 | Q ≤ 20, зөвхөн VISIT ба CURRENT |
| 2 | 30 | Q ≤ 1000 |
| 3 | 40 | Q ≤ 500000 |

## Жишээ

### Жишээ 1
**Оролт:**
```
9
CURRENT
VISIT google
VISIT facebook
CURRENT
BACK
CURRENT
FORWARD
BACK
BACK
```
**Гаралт:**
```
home
facebook
google
google
facebook
IGNORE
```

### Тайлбар

- CURRENT → "home"
- VISIT google → одоо: google
- VISIT facebook → одоо: facebook
- CURRENT → "facebook"
- BACK → google руу буцав → "google"
- CURRENT → "google"
- FORWARD → facebook руу → "facebook"
- BACK → google руу → хэвлэхгүй (BACK амжилттай = хуудсыг хэвлэнэ) → "google"...

Залруулга: BACK, FORWARD амжилттай бол одоогийн хуудсыг хэвлэнэ.

- home → VISIT google → VISIT facebook
- BACK → google, FORWARD → facebook, BACK → google, BACK → home
- Сүүлийн BACK → home-оос цааш буцах боломжгүй → IGNORE
