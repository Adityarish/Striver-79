/* ==========================================================================
   Striver-79 Explorer — script.js
   Vanilla JS. No frameworks. Fetches source directly from GitHub raw URLs.
   ========================================================================== */

const GITHUB_USER = "Adityarish";
const GITHUB_REPO = "Striver-79";
const GITHUB_BRANCH = "main";

const EXT_MAP = { cpp: "cpp", java: "java", python: "py" };
const LANG_LABEL = { cpp: "C++", java: "Java", python: "Python" };
const PRISM_LANG = { cpp: "cpp", java: "java", python: "python" };

const TOPIC_ICONS = {
  "Array and Hashing": "fa-solid fa-hashtag",
  "Binary Search": "fa-solid fa-magnifying-glass-chart",
  "Dynamic Programming": "fa-solid fa-diagram-project",
  "Graphs": "fa-solid fa-circle-nodes",
  "Heaps": "fa-solid fa-layer-group",
  "Linked List": "fa-solid fa-link",
  "Recursion and Backtracking": "fa-solid fa-arrow-rotate-left",
  "Stacks and Queues": "fa-solid fa-layer-group",
  "Strings": "fa-solid fa-font",
  "Trees (BT + BST)": "fa-solid fa-sitemap",
  "Tries": "fa-solid fa-code-branch",
};

/* ---------------------------------------------------------------------- */
/* Global state                                                           */
/* ---------------------------------------------------------------------- */
const state = {
  problems: [],
  topics: [],          // ordered unique topic names
  filteredProblems: [],
  activeProblem: null,
  activeLang: "cpp",
  searchTerm: "",
  filters: { difficulty: null, platform: null, language: "all" },
  wordWrap: false,
  codeCache: {},        // key: rawUrl -> code text
  solvedProblems: JSON.parse(localStorage.getItem("striver79-solved") || "[]"),
};

function toggleSolved(slug, checked) {
  if (checked) {
    if (!state.solvedProblems.includes(slug)) state.solvedProblems.push(slug);
  } else {
    state.solvedProblems = state.solvedProblems.filter(s => s !== slug);
  }
  localStorage.setItem("striver79-solved", JSON.stringify(state.solvedProblems));
}

/* ---------------------------------------------------------------------- */
/* Helpers                                                                 */
/* ---------------------------------------------------------------------- */
function rawUrlFor(problem, lang){
  const ext = EXT_MAP[lang];
  const path = `${problem.topic}/${lang}/${problem.slug}.${ext}`;
  const encodedPath = path.split("/").map(encodeURIComponent).join("/");
  return `./${encodedPath}`;
}

function githubBlobUrlFor(problem, lang){
  const ext = EXT_MAP[lang];
  const path = `${problem.topic}/${lang}/${problem.slug}.${ext}`;
  const encodedPath = path.split("/").map(encodeURIComponent).join("/");
  return `https://github.com/${GITHUB_USER}/${GITHUB_REPO}/blob/${GITHUB_BRANCH}/${encodedPath}`;
}

function escapeHtml(str){
  return str.replace(/[&<>"']/g, (c) => ({
    "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;",
  }[c]));
}

function showToast(message, type = "success"){
  const toast = document.getElementById("toast");
  const icon = type === "success" ? "fa-solid fa-circle-check" : "fa-solid fa-triangle-exclamation";
  toast.innerHTML = `<i class="${icon}"></i> ${escapeHtml(message)}`;
  toast.classList.add("show");
  clearTimeout(showToast._t);
  showToast._t = setTimeout(() => toast.classList.remove("show"), 2200);
}

/* ---------------------------------------------------------------------- */
/* loadProblems — fetch data/problems.json                                */
/* ---------------------------------------------------------------------- */
async function loadProblems(){
  try{
    const res = await fetch("striver-79-site/data/problems.json");
    if (!res.ok) throw new Error("Failed to load problems.json");
    const data = await res.json();
    state.problems = data;
    state.topics = [...new Set(data.map((p) => p.topic))];
    state.filteredProblems = data;
    return data;
  }catch(err){
    console.error(err);
    showToast("Could not load problem data.", "error");
    return [];
  }
}

/* ---------------------------------------------------------------------- */
/* renderSidebar — VS Code style collapsible topic tree                   */
/* ---------------------------------------------------------------------- */
function renderSidebar(){
  const tree = document.getElementById("sidebar-tree");
  tree.innerHTML = "";

  const isFiltering = state.searchTerm || state.filters.difficulty || state.filters.platform || (state.filters.language && state.filters.language !== "all");

  state.topics.forEach((topic, idx) => {
    const problemsInTopic = state.filteredProblems.filter((p) => p.topic === topic);
    if (problemsInTopic.length === 0) return;

    const icon = TOPIC_ICONS[topic] || "fa-solid fa-folder";

    const topicEl = document.createElement("div");
    topicEl.className = "tree-topic" + (idx === 0 || isFiltering ? " expanded" : "");
    topicEl.dataset.topic = topic;

    topicEl.innerHTML = `
      <button class="tree-topic-btn" data-action="toggle-topic">
        <i class="fa-solid fa-chevron-right"></i>
        <i class="${icon}"></i>
        <span>${escapeHtml(topic)}</span>
        <span class="tree-topic-count">${problemsInTopic.length}</span>
      </button>
      <div class="tree-items"></div>
    `;

    const itemsWrap = topicEl.querySelector(".tree-items");
    problemsInTopic.forEach((problem) => {
      const isSolved = state.solvedProblems.includes(problem.slug);

      const item = document.createElement("button");
      item.className = "tree-item" + (isSolved ? " solved" : "");
      if (state.activeProblem && state.activeProblem.slug === problem.slug && state.activeProblem.topic === problem.topic) {
        item.classList.add("active");
      }
      item.dataset.slug = problem.slug;
      item.dataset.topic = problem.topic;
      
      item.innerHTML = `
        <label class="custom-checkbox" title="Mark as solved" onclick="event.stopPropagation()">
          <input type="checkbox" class="solved-checkbox" ${isSolved ? 'checked' : ''}>
          <span class="checkmark"></span>
        </label>
        <span class="tree-item-title">${escapeHtml(problem.title)}</span>
      `;
      
      item.addEventListener("click", () => {
        navigateTo("explorer");
        renderProblem(problem);
        closeMobileDrawer();
      });

      const cb = item.querySelector('.solved-checkbox');
      cb.addEventListener("change", (e) => {
        toggleSolved(problem.slug, e.target.checked);
        item.classList.toggle("solved", e.target.checked);
      });

      itemsWrap.appendChild(item);
    });

    topicEl.querySelector('[data-action="toggle-topic"]').addEventListener("click", () => {
      topicEl.classList.toggle("expanded");
    });

    tree.appendChild(topicEl);
  });

  if (tree.innerHTML === "") {
    tree.innerHTML = `
      <div class="empty-state" style="padding: 40px 10px;">
        <i class="fa-solid fa-inbox"></i>
        <p style="font-size: 13px;">No problems match your search.</p>
      </div>`;
  }
}

function highlightSidebarActive(problem){
  document.querySelectorAll(".tree-item").forEach((el) => {
    el.classList.toggle("active", el.dataset.slug === problem.slug && el.dataset.topic === problem.topic);
  });
  // ensure the containing topic is expanded
  document.querySelectorAll(".tree-topic").forEach((el) => {
    if (el.dataset.topic === problem.topic) el.classList.add("expanded");
  });
}

/* ---------------------------------------------------------------------- */
/* renderTopicPreviewCards (landing page)                                 */
/* ---------------------------------------------------------------------- */
function renderTopicPreviewCards(){
  const wrap = document.getElementById("topic-cards");
  wrap.innerHTML = "";
  state.topics.forEach((topic) => {
    const count = state.problems.filter((p) => p.topic === topic).length;
    const icon = TOPIC_ICONS[topic] || "fa-solid fa-folder";
    const card = document.createElement("button");
    card.className = "topic-card";
    card.innerHTML = `
      <div class="topic-card-icon"><i class="${icon}"></i></div>
      <div>
        <div class="topic-card-name">${escapeHtml(topic)}</div>
        <div class="topic-card-count">${count} problem${count !== 1 ? "s" : ""}</div>
      </div>
    `;
    card.addEventListener("click", () => {
      navigateTo("explorer");
      state.searchTerm = topic;
      document.getElementById("problem-search-input").value = topic;
      searchProblems(topic);
    });
    wrap.appendChild(card);
  });
}

/* ---------------------------------------------------------------------- */
/* ---------------------------------------------------------------------- */
/* renderProblem — populate right-hand viewer for a given problem         */
/* ---------------------------------------------------------------------- */
function renderProblem(problem){
  state.activeProblem = problem;
  state.activeLang = problem.languages.includes(state.activeLang) ? state.activeLang : problem.languages[0];

  document.getElementById("viewer-empty").hidden = true;
  const content = document.getElementById("viewer-content");
  content.hidden = false;

  document.getElementById("viewer-title").textContent = problem.title;

  const diffBadge = document.getElementById("viewer-difficulty-badge");
  diffBadge.textContent = problem.difficulty;
  diffBadge.className = `badge badge-${problem.difficulty.toLowerCase()}`;

  document.getElementById("viewer-topic-badge").textContent = problem.topic;

  document.getElementById("viewer-leetcode-link").href = problem.leetcode;
  document.getElementById("viewer-gfg-link").href = problem.gfg;
  document.getElementById("viewer-github-link").href = githubBlobUrlFor(problem, state.activeLang);

  // language selector buttons — enable/disable based on availability
  document.querySelectorAll(".lang-btn").forEach((btn) => {
    const lang = btn.dataset.lang;
    const available = problem.languages.includes(lang);
    btn.disabled = !available;
    btn.style.opacity = available ? "1" : "0.35";
    btn.style.pointerEvents = available ? "auto" : "none";
    btn.classList.toggle("active", lang === state.activeLang);
  });

  highlightSidebarActive(problem);

  loadCode(problem, state.activeLang);

  document.getElementById("page-explorer").classList.add("viewer-active");

  if (window.innerWidth <= 1024){
    document.getElementById("viewer-panel").scrollIntoView({ behavior: "smooth" });
  }
}

/* ---------------------------------------------------------------------- */
/* loadCode — fetch raw source from GitHub and syntax-highlight it        */
/* ---------------------------------------------------------------------- */
async function loadCode(problem, lang){
  const url = rawUrlFor(problem, lang);
  const codeBlock = document.getElementById("code-block");
  const codeError = document.getElementById("code-error");
  const codeLoading = document.getElementById("code-loading");
  const codePre = document.getElementById("code-pre");

  document.getElementById("code-filename").textContent = `${problem.slug}.${EXT_MAP[lang]}`;
  document.getElementById("viewer-github-link").href = githubBlobUrlFor(problem, lang);

  codeError.hidden = true;
  codePre.style.display = "none";
  codeLoading.hidden = false;

  try{
    let code = state.codeCache[url];
    if (!code){
      const res = await fetch(url);
      if (!res.ok) throw new Error(`HTTP ${res.status}`);
      code = await res.text();
      state.codeCache[url] = code;
    }

    codeBlock.className = `language-${PRISM_LANG[lang]}`;
    codeBlock.textContent = code;
    codeLoading.hidden = true;
    codePre.style.display = "block";

    if (window.Prism){
      Prism.highlightElement(codeBlock);
    }
  }catch(err){
    console.error(err);
    codeLoading.hidden = true;
    codeError.hidden = false;
    document.getElementById("code-error-text").textContent =
      `Could not load ${problem.slug}.${EXT_MAP[lang]} from GitHub. It may not have been pushed yet.`;
  }
}

/* ---------------------------------------------------------------------- */
/* changeLanguage — switch active language and reload code                */
/* ---------------------------------------------------------------------- */
function changeLanguage(lang){
  if (!state.activeProblem) return;
  if (!state.activeProblem.languages.includes(lang)) return;
  state.activeLang = lang;
  document.querySelectorAll(".lang-btn").forEach((btn) => {
    btn.classList.toggle("active", btn.dataset.lang === lang);
  });
  loadCode(state.activeProblem, lang);
}

/* ---------------------------------------------------------------------- */
/* searchProblems — filters + text search combined                        */
/* ---------------------------------------------------------------------- */
function searchProblems(term){
  state.searchTerm = (term || "").trim().toLowerCase();
  applyFilters();
}

function applyFilters(){
  const term = state.searchTerm;
  const { difficulty, platform, language } = state.filters;

  state.filteredProblems = state.problems.filter((p) => {
    const matchesTerm = !term ||
      p.title.toLowerCase().includes(term) ||
      p.topic.toLowerCase().includes(term) ||
      p.languages.some((l) => l.includes(term) || LANG_LABEL[l].toLowerCase().includes(term));

    const matchesDifficulty = !difficulty || p.difficulty === difficulty;
    const matchesPlatform = !platform || (platform === "leetcode" ? !!p.leetcode : !!p.gfg);
    const matchesLanguage = !language || language === "all" || p.languages.includes(language);

    return matchesTerm && matchesDifficulty && matchesPlatform && matchesLanguage;
  });

  renderSidebar();

  const clearBtn = document.getElementById("clear-filters-btn");
  clearBtn.hidden = !(term || difficulty || platform || (language && language !== "all"));
}

/* ---------------------------------------------------------------------- */
/* toggleTheme — dark / light with localStorage persistence               */
/* ---------------------------------------------------------------------- */
function toggleTheme(){
  const html = document.documentElement;
  const next = html.dataset.theme === "dark" ? "light" : "dark";
  html.dataset.theme = next;
  localStorage.setItem("striver79-theme", next);
  updateThemeIcon(next);
}

function updateThemeIcon(theme){
  const icon = document.querySelector("#theme-toggle i");
  icon.className = theme === "dark" ? "fa-solid fa-moon" : "fa-solid fa-sun";
}

function initTheme(){
  const saved = localStorage.getItem("striver79-theme");
  const preferred = saved || "dark";
  document.documentElement.dataset.theme = preferred;
  updateThemeIcon(preferred);
}

/* ---------------------------------------------------------------------- */
/* copyCode / downloadCode                                                */
/* ---------------------------------------------------------------------- */
async function copyCode(){
  const codeBlock = document.getElementById("code-block");
  const text = codeBlock.textContent;
  if (!text) return;
  try{
    await navigator.clipboard.writeText(text);
    showToast("Code copied to clipboard");
  }catch(err){
    showToast("Could not copy code", "error");
  }
}

function downloadCode(){
  if (!state.activeProblem) return;
  const codeBlock = document.getElementById("code-block");
  const text = codeBlock.textContent;
  if (!text) return;
  const filename = `${state.activeProblem.slug}.${EXT_MAP[state.activeLang]}`;
  const blob = new Blob([text], { type: "text/plain" });
  const url = URL.createObjectURL(blob);
  const a = document.createElement("a");
  a.href = url;
  a.download = filename;
  document.body.appendChild(a);
  a.click();
  a.remove();
  URL.revokeObjectURL(url);
  showToast(`Downloaded ${filename}`);
}

/* ---------------------------------------------------------------------- */
/* Wrap / Fullscreen toggles                                              */
/* ---------------------------------------------------------------------- */
function toggleWrap(){
  const container = document.getElementById("code-container");
  state.wordWrap = !state.wordWrap;
  container.classList.toggle("wrapped", state.wordWrap);
  document.getElementById("wrap-btn").classList.toggle("active", state.wordWrap);
}

function toggleFullscreen(){
  const container = document.getElementById("code-container");
  container.classList.toggle("fullscreen");
  const icon = document.querySelector("#fullscreen-btn i");
  icon.className = container.classList.contains("fullscreen") ? "fa-solid fa-compress" : "fa-solid fa-expand";
}

/* ---------------------------------------------------------------------- */
/* Navigation between Home / Explorer "pages" (single-page app)           */
/* ---------------------------------------------------------------------- */
function navigateTo(page){
  const home = document.getElementById("page-home");
  const explorer = document.getElementById("page-explorer");

  home.hidden = page !== "home";
  explorer.hidden = page !== "explorer";

  document.querySelectorAll(".nav-link[data-nav]").forEach((el) => {
    el.classList.toggle("active", el.dataset.nav === page);
  });

  window.scrollTo({ top: 0, behavior: "instant" in window ? "instant" : "auto" });
  window.location.hash = page;
}

/* ---------------------------------------------------------------------- */
/* Mobile drawer (sidebar) controls                                       */
/* ---------------------------------------------------------------------- */
function openMobileDrawer(){
  document.getElementById("sidebar").classList.add("drawer-open");
  document.getElementById("drawer-overlay").classList.add("show");
}
function closeMobileDrawer(){
  document.getElementById("sidebar").classList.remove("drawer-open");
  document.getElementById("drawer-overlay").classList.remove("show");
}

/* ---------------------------------------------------------------------- */
/* Animated stat counters                                                 */
/* ---------------------------------------------------------------------- */
function animateStats(){
  document.querySelectorAll(".stat-value[data-count]").forEach((el) => {
    const target = parseInt(el.dataset.count, 10);
    let current = 0;
    const duration = 900;
    const start = performance.now();
    function tick(now){
      const progress = Math.min((now - start) / duration, 1);
      current = Math.round(progress * target);
      el.textContent = current;
      if (progress < 1) requestAnimationFrame(tick);
    }
    requestAnimationFrame(tick);
  });
}

/* ---------------------------------------------------------------------- */
/* Event wiring                                                            */
/* ---------------------------------------------------------------------- */
function wireEvents(){
  // Nav
  document.querySelectorAll("[data-nav]").forEach((el) => {
    el.addEventListener("click", () => navigateTo(el.dataset.nav));
  });

  // Theme
  document.getElementById("theme-toggle").addEventListener("click", toggleTheme);

  // Global search (redirects to explorer + filters)
  const globalSearch = document.getElementById("global-search-input");
  globalSearch.addEventListener("input", (e) => {
    navigateTo("explorer");
    document.getElementById("problem-search-input").value = e.target.value;
    searchProblems(e.target.value);
  });
  document.addEventListener("keydown", (e) => {
    if (e.key === "/" && document.activeElement.tagName !== "INPUT"){
      e.preventDefault();
      globalSearch.focus();
    }
    if (e.key === "Escape"){
      const container = document.getElementById("code-container");
      if (container.classList.contains("fullscreen")) toggleFullscreen();
    }
  });

  // Middle panel search
  document.getElementById("problem-search-input").addEventListener("input", (e) => {
    searchProblems(e.target.value);
  });

  // Filters
  document.querySelectorAll(".chip[data-filter]").forEach((chip) => {
    chip.addEventListener("click", () => {
      const filterType = chip.dataset.filter;
      const value = chip.dataset.value;
      const isActive = chip.classList.contains("active");

      document.querySelectorAll(`.chip[data-filter="${filterType}"]`).forEach((c) => c.classList.remove("active"));

      state.filters[filterType] = isActive ? null : value;
      if (!isActive) chip.classList.add("active");

      applyFilters();
    });
  });

  document.getElementById("clear-filters-btn").addEventListener("click", () => {
    state.filters = { difficulty: null, platform: null, language: "all" };
    state.searchTerm = "";
    document.getElementById("problem-search-input").value = "";
    document.getElementById("global-search-input").value = "";
    document.getElementById("global-lang-select").value = "all";
    document.querySelectorAll(".chip.active").forEach((c) => c.classList.remove("active"));
    applyFilters();
  });

  // Global Language Selector
  document.getElementById("global-lang-select").addEventListener("change", (e) => {
    const lang = e.target.value;
    state.filters.language = lang;
    if (lang !== "all") {
        state.activeLang = lang;
        if (state.activeProblem && state.activeProblem.languages.includes(lang)) {
            changeLanguage(lang);
        }
    }
    applyFilters();
  });

  // Language selector
  document.getElementById("lang-selector").addEventListener("click", (e) => {
    const btn = e.target.closest(".lang-btn");
    if (!btn || btn.disabled) return;
    changeLanguage(btn.dataset.lang);
  });

  // Code actions
  document.getElementById("copy-btn").addEventListener("click", copyCode);
  document.getElementById("download-btn").addEventListener("click", downloadCode);
  document.getElementById("wrap-btn").addEventListener("click", toggleWrap);
  document.getElementById("fullscreen-btn").addEventListener("click", toggleFullscreen);

  // Sidebar collapse (desktop)
  document.getElementById("sidebar-collapse-btn").addEventListener("click", () => {
    document.getElementById("page-explorer").classList.toggle("sidebar-collapsed");
  });

  // Mobile hamburger / Desktop collapse toggle
  document.getElementById("hamburger-btn").addEventListener("click", () => {
    if (document.getElementById("page-explorer").hidden){
      navigateTo("explorer");
    }
    if (window.innerWidth <= 1024) {
      openMobileDrawer();
    } else {
      document.getElementById("page-explorer").classList.toggle("sidebar-collapsed");
    }
  });
  document.getElementById("drawer-overlay").addEventListener("click", closeMobileDrawer);

  // Mobile: back button from viewer to list
  document.getElementById("viewer-close-btn").addEventListener("click", () => {
    document.getElementById("page-explorer").classList.remove("viewer-active");
  });
}

/* ---------------------------------------------------------------------- */
/* Init                                                                     */
/* ---------------------------------------------------------------------- */
async function init(){
  initTheme();
  wireEvents();

  await loadProblems();
  renderSidebar();
  renderTopicPreviewCards();
  animateStats();

  const startPage = window.location.hash === "#explorer" ? "explorer" : "home";
  navigateTo(startPage);

  const loader = document.getElementById("global-loader");
  loader.classList.add("hidden");
}

document.addEventListener("DOMContentLoaded", init);
